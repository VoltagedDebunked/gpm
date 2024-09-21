#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void install_package(const char *package) {
    char command[256];
    char manifest_path[256];
    snprintf(command, sizeof(command), "tar -xzf packages/%s -C installed/", package);

    printf("Installing package: %s...\n", package);
    int result = system(command);

    if (result == 0) {
        snprintf(manifest_path, sizeof(manifest_path), "installed/%s/manifest.txt", strip_extension(package));
        if (file_exists(manifest_path)) {
            printf("Reading manifest file...\n");
            char *dependencies = get_dependencies(manifest_path);
            if (dependencies) {
                printf("Installing dependencies: %s\n", dependencies);
                install_dependencies(dependencies);
            }
        }
        printf("Package %s installed successfully.\n", package);
    } else {
        printf("Failed to install package %s.\n", package);
    }
}