#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
 int main()
{
   char*cmnd="1s";
   char*arg_list[]={"1s","-1",NULL};
   printf("Before execvp()\n");
   printf("Creating another process using fork()\n");
pid_t p=fork();
int status=0;
if(p==0)
{ 
   printf("Child Process\n");
   status=execvp(cmnd,arg_list);
   if(status==-1)
   {
           printf("Incorrect Terminated\n");
           exit(1);
    }
}
else
{ 
    printf("Parent Process\n");
    wait(NULL);
    printf("Status:%d\n",status);
    printf("Now this line will be excuted\n");
}

}
