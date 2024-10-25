
#include <stdio.h>
#include <pwd.h>
#include "users.h"

void list_users(FILE *output) {
    struct passwd *pw;
    while ((pw = getpwent()) != NULL) {
        fprintf(output, "User: %s, Home: %s\n", pw->pw_name, pw->pw_dir);
    }
    endpwent();
}
