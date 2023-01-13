#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *thread1(void *arg);
void *thread2(void *arg);
void *deadlock_detect(void *arg);

pthread_mutex_t lock1;
pthread_mutex_t lock2;
int lock1th1 = 0, lock2th2 = 0;

int main()
{
    pthread_t tid[3];
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);
    pthread_create(&tid[0], NULL, &thread1, NULL);
    pthread_create(&tid[1], NULL, &thread2, NULL);
    pthread_create(&tid[2], NULL, &deadlock_detect, NULL);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);

    return 0;
}

void *thread1(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&lock1);
        lock1th1 = 1;
        for (int i = 0; i < 0xFFF; i++)
            ;
        pthread_mutex_lock(&lock2);
        lock1th1 = 0;
        for (int i = 0; 0xFFFFFF; i++)
            ;
        printf("1");
        pthread_mutex_unlock(&lock2);
        pthread_mutex_unlock(&lock1);
    }
}
void *thread2(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&lock2);
        lock2th2 = 1;
        for (int i = 0; i < 0xFFF; i++)
            ;
        pthread_mutex_lock(&lock1);
        lock2th2 = 0;
        for (int i = 0; 0xFFFFFF; i++)
            ;
        printf("2");
        pthread_mutex_unlock(&lock1);
        pthread_mutex_unlock(&lock2);
    }
}
void *deadlock_detect(void *arg)
{
    while (1)
    {
        fflush(stdout);
        for (int i = 0; i < 0xFFF; i++)
            ;
        if (lock1th1 && lock2th2)
        {
            pthread_mutex_destroy(&lock1);
            pthread_mutex_destroy(&lock2);
            break;
        }
    }
    printf("! Deadlock Occured ! (Ctrl+C to terminate) \n");
}
