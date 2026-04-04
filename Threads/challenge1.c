#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 10

void *fun(void * arg);

int count = 0;

int main(){
    pthread_t thread_id[NUM_THREADS];
    int values[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        values[i] = i;
        pthread_create(&thread_id[i], NULL, fun,&values[i]);
    } 

    for (int j = 0; j < NUM_THREADS; j++) {
        pthread_join(thread_id[j], NULL);
        pthread_exit(&thread_id[j]);
    } 


    return 0;
}

void *fun(void *arg){
    int *i = (int *) arg;

    count++;

    printf("Message is %d, thread_id: %lu modified counter to %d\n", *i, pthread_self(), count);
}

