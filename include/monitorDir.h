#include <stdio.h>
#include <unistd.h>
#include <complex.h>
#include <sys/inotify.h>
#include "readExtension.h"

#define MAX_EVENT_SIZE 2048
#define NAME_LEN 32             /* File Name Length */
#define MONITOR_EVENT_SIZE (sizeof(struct inotify_event))       /* Size Of One Event */
#define BUFFER_LEN MAX_EVENT_SIZE*(MONITOR_EVENT_SIZE+NAME_LEN) /* Buffer Length */

int monitorDir(char path[]) {

    int fd, wd;
    char buffer[BUFFER_LEN];

    fd = inotify_init();
    if (fd < 0) {
        perror("Notify not initialized !\n");
        exit(1);
    }

    wd = inotify_add_watch(fd, path, IN_MODIFY | IN_DELETE);
    if (wd < 0) {
        printf("Couldn't add watch to %s\n", path);
        exit(1);
    }
    else {
        printf("Monitor Added To : %s\n", path);
    }

    int i;
    while (1) {
        i = 0;
        int total_read = read(fd, buffer, BUFFER_LEN);
        if (read < 0) {
            perror("Read Error\n");
            exit(1);
        }
        
        while (i < total_read) {
            struct inotify_event *event = (struct inotify_event *)&buffer[i];
            if (event -> len) {
                if (event -> mask & IN_MODIFY) {
                    if (event -> mask & IN_ISDIR) {
                        printf("Directory Modified : \"%s\"\n", event -> name);
                    }
                    else {
                        readExtension(event -> name, path);
                    }
                }
                i += MONITOR_EVENT_SIZE + event -> len;
            }
        }

    }

    inotify_rm_watch(fd, wd);
    close(fd);
    return 0;

}
