#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getFileNameWithoutExt(char[]);

int runProgram(char fileName[], char ext[]) {

    char *extName[] = {"c", "cpp"};
    char *command[] = {"gcc", "g++"};
    int size = 2;

    int commandIndex = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(ext, extName[i]) == 0) {
            commandIndex = i;
            break;
        }
    }


    char finalCommand[2048] = "";
    strcat(finalCommand, command[commandIndex]);
    strcat(finalCommand, " ");
    strcat(finalCommand, fileName);
    char *finalOuputFile = getFileNameWithoutExt(fileName);  
    strcat(finalCommand, " ");
    strcat(finalCommand, "-o");
    strcat(finalCommand, " ");
    strcat(finalCommand, finalOuputFile);

    printf("%s\n", finalCommand);

    int compileResult = system(finalCommand);
    if (compileResult == -1) {
        perror("compilation error\n");
        exit(1);
    }

    printf("compilation complete\n");
    
    int runResult = system(finalOuputFile);
    if (runResult == -1) {
        perror("run error\n");
        exit(1);
    }

    return 0;
}

char *getFileNameWithoutExt(char fileName[]) {

    char *filename_no_ext;
    fileName[strcspn(fileName, "\n")] = '\0';
    filename_no_ext = strrchr(fileName, '.');
    if (filename_no_ext != NULL) {
        *filename_no_ext = '\0';
    }
    return fileName;

}
