#ifndef UTILS_H
#define UTILS_H

int file_exists(const char *path);
char* get_dependencies(const char *manifest_path);
char* strip_extension(const char *filename);
void install_dependencies(char *dependencies);
char* get_version(const char *manifest_path);

#endif // UTILS_H