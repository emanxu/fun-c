#include <pthread.h>
#include <stdio.h>

// Thread type
// void * _Nullable (* _Nonnull)(void * _Nullable)

// Thread function that does not take any argument
void *foo(void *arg) {
  printf("Created a new thread\n");
  return NULL;
}

// Thread function that takes an argument
void *bar(void *arg) {
  // Cast the argument to the expected type
  const char *message = (const char *)arg;
  printf("argument passed to thread: %s\n", message);
  return NULL;
}

int main() {

  // Create a pthread_t variable to store thread ID
  pthread_t thread1;
  pthread_t thread2;

  // Creating a new thread.
  pthread_create(&thread1, NULL, foo, NULL);

  // Creating a new thread with argument.
  const char *message = "Hello, World!";
  pthread_create(&thread2, NULL, bar, (void *)message);

  // Wait for thread to finish
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0;
}
