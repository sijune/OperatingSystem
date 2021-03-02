
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


int value = 0;
void *runner(void *param);

int main(int argc, char *argv[]){
    pthread_t tid;
    pthread_attr_t attr;
    pid_t pid;

    pid = fork();

    if(pid==0){
        pthread_attr_init(&attr);
        pthread_create(&tid, &attr, runner, NULL);
        pthread_join(tid, NULL);
        printf("CHILD VALUE = %d\n", value);
    } else if (pid > 0){
        wait(NULL);
        printf("PARENT VALUE = %d\n", value);
    }
}

void *runner(void *param){
    value = 5;
    pthread_exit(0);
    
}