
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <omp.h>

int main(int argc, char *argv[]){
    //병렬적으로 실행해라!
    #pragma omp parallel
    {
        printf("i am a parallel\n");
    }

    return 0;
}
