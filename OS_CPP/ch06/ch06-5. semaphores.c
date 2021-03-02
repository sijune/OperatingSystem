#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int sum = 0;

sem_t sem;

void *counter(void *param){
    int i;
    for( i = 0; i < 10000; i++)
    {   
        sem_wait(&sem);

        sum++;

        sem_post(&sem);
    }
    pthread_exit(0);
}

int main(){
    pthread_t tid1, tid2;
    sem_init(&sem, 0, 1); //두번째 매개변수는 리눅스 유형 운영체제에서 0으로 고정시켜놓으면 된다.
    pthread_create(&tid1, NULL, counter, NULL);
    pthread_create(&tid2, NULL, counter, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("%d\n", sum);
}
