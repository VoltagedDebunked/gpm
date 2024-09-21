#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void update_package(const char *package) {
    char installed_manifest[256], new_manifest[256];
    snprintf(installed_manifest, sizeof(installed_manifest), "installed/%s/manifest.txt", strip_extension(package));
    snprintf(new_manifest, sizeof(new_manifest), "packages/%s/manifest.txt", package);

    if (file_exists(installed_manifest)) {
        char *installed_version = get_version(installed_manifest);
        char *new_version = get_version(new_manifest);

        if (new_version && strcmp(installed_version, new_version) != 0) {
            printf("Updating package: %s (from version %s to %s)\n", package, installed_version, new_version);
            remove_package(package);
            install_package(package);
        } else {
            printf("Package %s is already up to date.\n", package);
        }
    } else {
        printf("Package %s is not installed.\n", package);
    }
}

char* get_version(const char *manifest_path) {
    static char version[256];
    FILE *file = fopen(manifest_path, "r");
    if (!file) {
        return NULL;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "version:", 8) == 0) {
            strcpy(version, line + 9);
            version[strcspn(version, "\n")] = 0;
            fclose(file);
            return version;
        }
    }

    fclose(file);
    return NULL;
}