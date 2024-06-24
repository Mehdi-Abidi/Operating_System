#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define NUM_CUSTOMERS 10
sem_t luggage_weighing_station;
sem_t luggage_security_check;
sem_t boarding_pass_counter;
void* customer(void* arg) {
    int customer_id = *((int*)arg);
    sem_wait(&luggage_weighing_station);
    printf("Customer %d is weighing luggage...\n", customer_id);
    sleep(4);
    printf("Customer %d finished weighing luggage\n", customer_id);
    sem_post(&luggage_weighing_station);
    sem_wait(&luggage_security_check);
    printf("Customer %d is undergoing luggage security check...\n", customer_id);
    sleep(7);
    printf("Customer %d finished luggage security check\n", customer_id);
    sem_post(&luggage_security_check);
    sem_wait(&boarding_pass_counter);
    printf("Customer %d is getting a boarding pass...\n", customer_id);
    sleep(3);
    printf("Customer %d got the boarding pass\n", customer_id);
    sem_post(&boarding_pass_counter);
    return NULL;
}
int main() {
    pthread_t customers[NUM_CUSTOMERS];
    int customer_ids[NUM_CUSTOMERS];
    sem_init(&luggage_weighing_station, 0, 1);
    sem_init(&luggage_security_check, 0, 1);
    sem_init(&boarding_pass_counter, 0, 1);
    for (int i = 0; i < NUM_CUSTOMERS; ++i) {
        customer_ids[i] = i + 1;
        pthread_create(&customers[i], NULL, customer, &customer_ids[i]);
    }
    for (int i = 0; i < NUM_CUSTOMERS; ++i) {
        pthread_join(customers[i], NULL);
    }
    sem_destroy(&luggage_weighing_station);
    sem_destroy(&luggage_security_check);
    sem_destroy(&boarding_pass_counter);
    return 0;
}
