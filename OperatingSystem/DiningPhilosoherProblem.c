#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5  // Number of philosophers

sem_t chopstick[N];  // One semaphore for each chopstick

void* philosopher(void* num) {
    int id = *(int*)num;

    while (1) {
        printf("Philosopher %d is thinking...\n", id);
        sleep(1);

        // Pick up left chopstick
        sem_wait(&chopstick[id]);

        // Pick up right chopstick
        sem_wait(&chopstick[(id + 1) % N]);

        printf("Philosopher %d is eating...\n", id);
        sleep(2);

        // Put down left chopstick
        sem_post(&chopstick[id]);

        // Put down right chopstick
        sem_post(&chopstick[(id + 1) % N]);

        printf("Philosopher %d finished eating and put down chopsticks.\n", id);
    }
}

int main() {
    pthread_t threads[N];
    int i,philosopher_ids[N];

    // Initialize semaphores (each chopstick available = 1)
    for (i = 0; i < N; i++) {
        sem_init(&chopstick[i], 0, 1);
    }

    // Create philosopher threads
    for (i = 0; i < N; i++) {
        philosopher_ids[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &philosopher_ids[i]);
    }

    // Join threads (this program runs indefinitely)
    for (i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphores (unreachable but good practice)
    for (i = 0; i < N; i++) {
        sem_destroy(&chopstick[i]);
    }

    return 0;
}

