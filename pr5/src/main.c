
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "users.h"
#include "processes.h"
#include "log.h"
#include "error.h"

void print_help() {
    printf("Usage: program [options]\n");
    printf("Options:\n");
    printf("  -u, --users        List users and their home directories\n");
    printf("  -p, --processes    List running processes\n");
    printf("  -h, --help         Display this help message\n");
    printf("  -l PATH, --log PATH  Redirect output to file at PATH\n");
    printf("  -e PATH, --errors PATH Redirect stderr output to file at PATH\n");
}

int main(int argc, char *argv[]) {
    FILE *log_file = stdout;
    FILE *error_file = stderr;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "--users") == 0) {
            list_users(log_file);
        } else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--processes") == 0) {
            list_processes(log_file);
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            return 0;
        } else if ((strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--log") == 0) && i + 1 < argc) {
            log_file = fopen(argv[++i], "w");
            if (!log_file) {
                fprintf(error_file, "Error: Cannot open log file %s\n", argv[i]);
                return 1;
            }
        } else if ((strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--errors") == 0) && i + 1 < argc) {
            error_file = fopen(argv[++i], "w");
            if (!error_file) {
                fprintf(stderr, "Error: Cannot open error file %s\n", argv[i]);
                return 1;
            }
            stderr = error_file;
        } else {
            fprintf(error_file, "Unknown argument: %s\n", argv[i]);
            return 1;
        }
    }

    if (log_file != stdout) fclose(log_file);
    if (error_file != stderr) fclose(error_file);

    return 0;
}
