#include <stdio.h>
#include <stdlib.h>

void remove_package(const char *package) {
    char command[256];
    snprintf(command, sizeof(command), "rm -rf installed/%s", package);

    printf("Removing package: %s...\n", package);
    int result = system(command);

    if (result == 0) {
        printf("Package %s removed successfully.\n", package);
    } else {
        printf("Failed to remove package %s.\n", package);
    }
}