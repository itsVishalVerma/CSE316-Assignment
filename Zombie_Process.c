//Coded by Vishal; roll no.- 18 ; UID - 11615139.

/*
 * Creation of Zombie Process.
 *
 * A zombie process is that process which has completed execution via the exit system call,
   but still has an entry in the process table.
 * So, we create two child processes and makes the parent sleep for 20 seconds (and not wait for the child).
 * Thus the child process becomes a zombie process.
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
    for (i = 0; i < 2; ++i){
        pid = fork();
        if (pid == 0){
            printf("\nChild process having PID: %d", getpid());
            exit(0); // Let the child process exit immediately.
        }
        else if (pid > 0){
            printf("\nParent process having PID: %d", getppid());
        }
        else{
            perror("Fork failed!\n");
            exit(1);
        }
    }
    //parent process sleep for 20 seconds and then exit.
    sleep(20);
    exit(0);
}
