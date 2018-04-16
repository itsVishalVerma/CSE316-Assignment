//Coded by Vishal; roll no.- 18 ; UID - 11615139.
// orphan process
/*
    # The parent process will exit immediately.
    # The child process will exit after sleeping for 20 seconds.
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include <unistd.h>
#include <process.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    int i;

    for (i = 0; i < 2; ++i) {
        pid = fork();
        if (pid < 0){
            printf("Fork failed!\n");
            exit(1);
        }
        else if (pid == 0){
            // Child process.
            printf("\nChild process having PID: %d", getpid());
            printf("\nParent Process has exited. Now I am orphan process.\nGoing to sleep");
            sleep(20); // Let the child process sleep for 30 seconds.
        }
        else if(pid > 0){
            // parent process.
            printf("\nParent process having PID: %d",getppid());
        }
    }
    exit(0);
}
