#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <strings.h>
#include <unistd.h>
#include <sys/stat.h>
#include "runProgram.h"

char *getExtension(char[]);

#define LOGIN_NAME_MAX 50
#define MAX_LINE_LENGHT 128
#define MAX_SECTION_NAME 32


int readExtension(char name[], char path[]) {

    char fileName[100] = "";
    strcat(fileName, path);
    strcat(fileName, "/");
    strcat(fileName, name);

    char *extension = getExtension(fileName);
    if (extension == NULL) {
        return 1;
    }

    runProgram(fileName, extension);
    return 0;
}

char *getExtension(char fileName[]) {

    char *dot = strchr(fileName, '.');
    if (dot != NULL && dot != fileName) {
        return dot + 1;
    }

    return NULL;

}
