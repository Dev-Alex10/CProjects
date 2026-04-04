#include <pthread.h>
#include <stdio.h>
#include<unistd.h>

#define NUM_THREADS 10

void *fun(void * arg);

int count = 0;
int threads_finished = 0;
pthread_mutex_t mutex;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

int main(){
    pthread_t thread_id[NUM_THREADS];
    int values[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        values[i] = i;
        pthread_create(&thread_id[i], NULL, fun,&values[i]);
    } 

    sleep(1);
    while (1) {
        if (threads_finished == NUM_THREADS/2) {
            pthread_cond_broadcast(&condition);
            break;
        }
    }

    for (int j = 0; j < NUM_THREADS; j++) {
        pthread_join(thread_id[j], NULL);
        pthread_exit(&thread_id[j]);
    } 
    pthread_mutex_destroy(&mutex);

    return 0;
}

void *fun(void *arg){
    int *i = (int *) arg;
    pthread_mutex_lock(&mutex);

    if (*i % 2 != 0) {
        pthread_cond_wait(&condition, &mutex);
    }

    threads_finished++;
    count++;

    printf("Message is %d, thread_id: %lu modified counter to %d\n", *i, pthread_self(), count);
    printf("Message is %d, thread_id: %lu modified counter to %d\n", *i, pthread_self(), count);
    
    pthread_mutex_unlock(&mutex);

    return NULL;
}

