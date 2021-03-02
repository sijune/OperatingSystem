#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
# include <semaphore.h>

#define true 1
#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];

pthread_mutex_t mutex;
sem_t empty, full;

int in = 0, out = 0;

void insert_item(int item){
    sem_wait(&empty); //wait()함수 코드를 생각하자
    pthread_mutex_lock(&mutex);

    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE;
    printf("Producer: inserted $%d\n", item);

    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}

void remove_item(int *item){
    sem_wait(&full);
    pthread_mutex_lock(&mutex);

    *item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    printf("Consumer: removed $%d\n", *item);

    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}

void *producer(void *param){
    int item;
    while(true){
        usleep((1+rand() % 5) * 100000); //마이크로초 단위 지연
        item = 1000 + rand() % 1000;
        insert_item(item); //cs
    }
}

void *consumer(void *param){
    int item;
    while(true){
        usleep((1+rand() % 5) * 100000);
        remove_item(&item); //cs
    }
}

int main(int argc, char *argv[]){
    int i, numOfProducers = 1, numOfConsumers = 1;
    pthread_t tid;

    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    srand(time(0)); //rand()호출 시 무작위 랜덤 숫자가 나오게 된다.
    for (i = 0; i < numOfProducers; i++){
        pthread_create(&tid, NULL, producer, NULL);
    }
    for (i = 0; i < numOfProducers; i++){
        pthread_create(&tid, NULL, consumer, NULL);
    }
    
    sleep(10); //10초간 수행
    return 0;

}

