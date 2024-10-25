#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "users.h"
#include "processes.h"
#include "help.h"
#include "utils.h"
#include "utils.h"
#include <locale.h>



int main(int argc, char *argv[])
{
    char *log_path = NULL;
    char *errors_path = NULL;

    if (argc == 1)
    {
        fprintf(stderr, "Не указаны аргументы. Используйте -h или --help для справки.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-u") == 0 || strcmp(argv[i], "--users") == 0)
        {
            users_func();
        }
        else if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--processes") == 0)
        {
            processes_func();
        }
        else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            help_func();
            return 0;
        }
        else if (strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--log") == 0)
        {
            if (i + 1 < argc)
            {
                log_path = argv[i + 1];
                if (check_path(log_path))
                {
                    return 1;
                }
                i++;
                freopen(log_path, "w", stdout);
                freopen(log_path, "w", stderr);
            }
            else
            {
                fprintf(stderr, "Ошибка: Не указан путь для записи лога.\n");
                return 1;
            }
        }
        else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--errors") == 0)
        {
            if (i + 1 < argc)
            {
                errors_path = argv[i + 1];
                if (check_path(errors_path))
                {
                    return 1;
                }
                i++;
                freopen(errors_path, "w", stderr);
            }
            else
            {
                fprintf(stderr, "Ошибка: Не указан путь для записи ошибок.\n");
                return 1;
            }
        }
        else
        {
            fprintf(stderr, "Неверный аргумент: %s\n", argv[i]);
            return 1;
        }
    }

    return 0;
}
