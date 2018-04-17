#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/stat.h>
void main()
{
char ans;
pid_t p=fork();
if(p<0)
printf("process creation unsuccessful\n..");
else if(p==0)
{
printf("\n In child process..\n");
char random[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
while(ans!='n')
{
char letter=random[rand()%26];
printf("%c",letter);
scanf("%s",&ans);
}
}
else if(p>0)
{
printf("in parent process\n");
wait();
}
}
