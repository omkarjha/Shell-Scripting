// Producer-Consumer with User Input
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_BUFFER 10
int buffer[MAX_BUFFER];
int in = 0, out = 0;

sem_t empty, full, mutex;

void *producer(void *arg) {
    int item;
    int num_items;
    printf("Enter number of items to produce: ");
    scanf("%d", &num_items);
    
    for(int i = 0; i < num_items; i++) {
        printf("Enter item %d to produce: ", i+1);
        scanf("%d", &item);
        
        sem_wait(&empty);
        sem_wait(&mutex);
        
        buffer[in] = item;
        printf("Producer produced: %d at position: %d\n", item, in);
        in = (in + 1) % MAX_BUFFER;
        
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
}

void *consumer(void *arg) {
    int item;
    int num_items;
    printf("Enter number of items to consume: ");
    scanf("%d", &num_items);
    
    for(int i = 0; i < num_items; i++) {
        sem_wait(&full);
        sem_wait(&mutex);
        
        item = buffer[out];
        printf("Consumer consumed: %d from position: %d\n", item, out);
        out = (out + 1) % MAX_BUFFER;
        
        sem_post(&mutex);
        sem_post(&empty);
        sleep(2);
    }
}

int main() {
    pthread_t prod, cons;
    
    sem_init(&empty, 0, MAX_BUFFER);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    
    printf("Producer-Consumer Problem\n");
    
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    
    return 0;
}
