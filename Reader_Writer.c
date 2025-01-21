// 2. READER-WRITER PROBLEM
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, writeblock;
int data = 0, rcount = 0;

void *reader(void *arg) {
    int f = *((int*)arg);
    while(1) {
        sem_wait(&mutex);
        rcount++;
        if(rcount == 1)
            sem_wait(&writeblock);
        sem_post(&mutex);
        
        printf("Reader %d: read data as %d\n", f, data);
        
        sem_wait(&mutex);
        rcount--;
        if(rcount == 0)
            sem_post(&writeblock);
        sem_post(&mutex);
        sleep(1);
    }
}

void *writer(void *arg) {
    int f = *((int*)arg);
    while(1) {
        sem_wait(&writeblock);
        data++;
        printf("Writer %d: wrote data as %d\n", f, data);
        sem_post(&writeblock);
        sleep(1);
    }
}

int main() {
    pthread_t rtid[5], wtid[5];
    sem_init(&mutex, 0, 1);
    sem_init(&writeblock, 0, 1);
    
    int a[5] = {1,2,3,4,5};
    
    for(int i = 0; i < 5; i++) {
        pthread_create(&wtid[i], NULL, writer, &a[i]);
        pthread_create(&rtid[i], NULL, reader, &a[i]);
    }
    
    for(int i = 0; i < 5; i++) {
        pthread_join(wtid[i], NULL);
        pthread_join(rtid[i], NULL);
    }
    
    return 0;
}
