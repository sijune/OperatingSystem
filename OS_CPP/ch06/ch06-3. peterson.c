
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define true 1
#define false 0

int sum = 0;

int turn; // 임계구역으로 들어갈 순번을 뜻함
int flag[2]; //임계구역으로 들어갈 준비가 되었다는 것을 뜻함

void *producer(void *param){
    int i;
    for( i = 0; i < 1000000; i++)
    {   
        flag[0] = true;
        turn = 1;
        while(flag[1] == true && turn == 1);
        
        /* CS start */
        sum++;
        /* CS end */
        
        flag[0] = false;
    }
    pthread_exit(0);
}

void *consumer(void *param){
    int i;
    for( i = 0; i < 1000000; i++)
    {   
        flag[1] = true;
        turn = 0;
        while(flag[0] == true && turn == 0);
        
        /* CS start */
        sum--;
        /* CS end */

        flag[1] = false;
    }
    pthread_exit(0);
}

int main(){
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, consumer, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("%d\n", sum);
}
