// Coded by Vishal; roll no.- 18 ; UID - 11615139 .
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include <unistd.h>
#include <process.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid; // Store the process ID.
    int i; // An integer variable to store the input.
    printf("\nEnter any number:");
    scanf("%d",&i);
    if(i<=1){
    	printf("\nEntered number is wrong!(Please enter any number greater than 1):");
    	scanf("%d",&i);
    }
    pid = fork();
    if(pid == -1){
    	// Process creation failed.
        printf("\n\nFailed to create the child process.");
        exit(1); // Abort the program.
    }
    else if(pid==0){
    	//process is created successfully.
    	printf("\nIt is Child process having PID: %d",getpid());
    	while(i>0){
    		printf("\n%d",i);
    		i = i/2;
    	}
    }
    else if(pid>0){
    	//parent process
        wait();
    	printf("\n It is parent process having PID: %d",getppid());
    }
}