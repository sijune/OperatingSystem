#include <stdio.h>
#include <pthread.h>

int sum = 0;

pthread_mutex_t mutex;

void *counter(void *param){
    int i;
    for( i = 0; i < 1000000; i++)
    {   
        pthread_mutex_lock(&mutex);

        sum++;

        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(0);
}

int main(){
    pthread_t tid1, tid2;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&tid1, NULL, counter, NULL);
    pthread_create(&tid2, NULL, counter, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("%d\n", sum);
}
