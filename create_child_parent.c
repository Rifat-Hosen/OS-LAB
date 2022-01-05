#include<stdio.h>
#include<unistd.h>

int main(){


    pid_t cpid,pid,cpid1;
    int i=0;

    cpid = fork();

    if(cpid<0){
        printf("Invalid");

    }
    else if(cpid ==0){
        cpid = getpid();
        printf("I am child    %u\n",cpid);

    }
    else if (cpid>0){
        pid = getpid();
        printf("Parent = %u Child %u\n",pid,cpid);
    }


    return 0;
}
