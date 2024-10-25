
#include <stdio.h>
#include <stdlib.h>
#include "processes.h"

void list_processes(FILE *output) {
    FILE *fp = popen("ps -e --sort=pid", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        fprintf(output, "%s", line);
    }
    pclose(fp);
}
