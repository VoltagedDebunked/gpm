#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int file_exists(const char *path) {
    FILE *file = fopen(path, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

char* get_dependencies(const char *manifest_path) {
    static char dependencies[256];
    FILE *file = fopen(manifest_path, "r");
    if (!file) {
        return NULL;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "dependencies:", 13) == 0) {
            strcpy(dependencies, line + 14);
            dependencies[strcspn(dependencies, "\n")] = 0;
            fclose(file);
            return dependencies;
        }
    }

    fclose(file);
    return NULL;
}

char* strip_extension(const char *filename) {
    static char name[256];
    strcpy(name, filename);
    char *dot = strrchr(name, '.');
    if (dot && !strcmp(dot, ".tar.gz")) {
        *dot = '\0';
    }
    return name;
}

void install_dependencies(char *dependencies) {
    char *dep = strtok(dependencies, " ");
    while (dep != NULL) {
        install_package(dep);
        dep = strtok(NULL, " ");
    }
}