#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void install_package(const char *package);
void list_packages();
void remove_package(const char *package);
void update_package(const char *package);

void show_help() {
    printf("GNU Package Manager (gpm)\n");
    printf("Usage: gpm <command> [package]\n");
    printf("Commands:\n");
    printf("  install <package>  Install a package\n");
    printf("  list               List installed packages\n");
    printf("  remove <package>   Remove a package\n");
    printf("  update <package>   Update a package\n");
    printf("  help               Show this message\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        show_help();
        return 1;
    }

    const char *command = argv[1];

    if (strcmp(command, "install") == 0) {
        if (argc < 3) {
            printf("Please specify a package to install.\n");
            return 1;
        }
        install_package(argv[2]);
    } else if (strcmp(command, "list") == 0) {
        list_packages();
    } else if (strcmp(command, "remove") == 0) {
        if (argc < 3) {
            printf("Please specify a package to remove.\n");
            return 1;
        }
        remove_package(argv[2]);
    } else if (strcmp(command, "update") == 0) {
        if (argc < 3) {
            printf("Please specify a package to update.\n");
            return 1;
        }
        update_package(argv[2]);
    } else {
        show_help();
    }

    return 0;
}