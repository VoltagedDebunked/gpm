#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void list_packages() {
    printf("Installed packages:\n");
    system("ls installed/");

    // For each package, display its version
    // This is a simple loop that can read manifest.txt in the installed directory.
}