#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/jail.h>

int main(int argc, char **argv) {
    while (1) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(1);
        }

        if (pid == 0) {
            // This is the child process
            struct iovec jail_params[] = {
                {"name", "infinite-process-tree-jail", strlen("infinite-process-tree-jail") + 1},
                {"path", "/", strlen("/") + 1},
                {"host.hostname", "infinite-process-tree-jail", strlen("infinite-process-tree-jail") + 1}
            };
            int jail_id = jail_setv(jail_params, 3, 0);
            if (jail_id == -1) {
                perror("jail_setv");
                exit(1);
            }

            // Rename the executable process's name randomly
            char new_process_name[20];
            sprintf(new_process_name, "pid-%d", getpid());
            setproctitle(new_process_name);
        } else {
            // This is the parent process
            int status;
            wait(&status);
        }
    }

    return 0;
}
