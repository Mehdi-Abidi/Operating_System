#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
int ice_cream_remaining = 10;
sem_t ice_cream_lock;
void* eat(void* arg) {
    int person_id = *((int*)arg);
    printf("Person %d created\n", person_id);
    while (1) {
        sem_wait(&ice_cream_lock);
        if (ice_cream_remaining > 0) {
            ice_cream_remaining--;
            printf("Person %d is eating an ice cream. Ice creams remaining: %d\n", person_id, ice_cream_remaining);
        }
        sem_post(&ice_cream_lock);
        sleep(1);
        if (ice_cream_remaining <= 0) {
            printf("Person %d finished eating\n", person_id);
            break;
        }
    }
    return NULL;
}
int main() {
    if (sem_init(&ice_cream_lock, 0, 1) != 0) {
        perror("Semaphore initialization failed");
        exit(EXIT_FAILURE);
    }
    printf("Semaphore initialized\n");
    pthread_t person_threads[3];
    int person_ids[3] = {1, 2, 3};
    for (int i = 0; i < 3; ++i) {
        if (pthread_create(&person_threads[i], NULL, eat, &person_ids[i]) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
        printf("Thread for Person %d created\n", person_ids[i]);
    }
    for (int i = 0; i < 3; ++i) {
        if (pthread_join(person_threads[i], NULL) != 0) {
            perror("Thread join failed");
            exit(EXIT_FAILURE);
        }
        printf("Thread for Person %d joined\n", person_ids[i]);
    }
    printf("All ice creams have been eaten!\n");
    if (sem_destroy(&ice_cream_lock) != 0) {
        perror("Semaphore destruction failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
