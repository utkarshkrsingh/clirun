#include <linux/limits.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include "include/monitorDir.h"

int main(int argc, char *argv[]) {

    /* if more than one path given */
    if (argc > 2) {
        printf("Too many arguments !");
        exit(1);
    }

    /* if exactly one path is given */
    else if (argc == 2) {
        DIR *dObj;
        dObj = opendir(argv[1]);
        /* check whether the path exists or not */
        if (dObj == NULL) {
            printf("Directory Not Exists : %s\n", argv[1]);
            exit(1);
        }
        monitorDir(argv[1]);
    }

    /* if no path is given then find out the current working directory */
    else if (argc < 2) {
        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("Current WD : %s\n", cwd);
            monitorDir(cwd);
        }
        else {
            perror("getcwd() error");
            exit(1);
        }
    }

    return 0;

}
