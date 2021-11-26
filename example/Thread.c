#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <threads.h>

void *print_message_function(void *ptr);

int main() {
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";

    pthread_create(&thread1, NULL, print_message_function, (void *) message1);
    pthread_create(&thread2, NULL, print_message_function, (void *) message2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

}

void *print_message_function(void *pasdtr) {
    char *message;

    message = (char *) pasdtr;
    printf("%d  %s \n",   thrd_current(),message);
}
