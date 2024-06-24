#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define NUM_SELLERS 2
#define TOTAL_TICKETS 10
int tickets_available = TOTAL_TICKETS;
sem_t ticket_semaphore;
void* ticket_seller(void* arg) {
    int seller_id = *((int*)arg);
    while (1) {
        sem_wait(&ticket_semaphore);
        if (tickets_available > 0) {
            printf("Ticket Seller %d sold a ticket. Tickets remaining: %d\n", seller_id, --tickets_available);
        } else {
            printf("Ticket Seller %d sold out!\n", seller_id);
            sem_post(&ticket_semaphore);
            break;
        }
        sem_post(&ticket_semaphore);
        sleep(1);
    }
    return NULL;
}
int main() {
    pthread_t sellers[NUM_SELLERS];
    int seller_ids[NUM_SELLERS];
    sem_init(&ticket_semaphore, 0, NUM_SELLERS);
    for (int i = 0; i < NUM_SELLERS; ++i) {
        seller_ids[i] = i + 1;
        pthread_create(&sellers[i], NULL, ticket_seller, &seller_ids[i]);
    }
    for (int i = 0; i < NUM_SELLERS; ++i) {
        pthread_join(sellers[i], NULL);
    }
    sem_destroy(&ticket_semaphore);
    return 0;
}
