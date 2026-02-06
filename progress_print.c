#include <stdio.h>
#include <time.h>
#include <unistd.h>

// print_wait print wait message
void print_wait(int second) { printf(" [wait %ds] ", second); }

// progress_one_line
// print the progress status in one line
void progress_one_line(int percent) {
  int bar_width = 50;
  int filled = (percent * bar_width) / 100;

  // back to first of the line
#ifdef _WIN32
  printf("\r\n");
#else
  printf("\r");
#endif

  printf("[");
  for (int i = 0; i < bar_width; i++) {
    if (i < filled) {
      printf("=");
    } else if (i == filled) {
      printf(">");
    } else {
      printf(" ");
    }
  }
  printf("] %3d%%", percent);

  // flush
  fflush(stdout);
}

// call back function pointer
typedef int (*time_callback)(void);

// progress_with_callback
// use callback function to get sleep interval
// time_callback is a function pointer
void progress_with_callback(time_callback callback, int total_steps) {
  for (int i = 0; i <= total_steps; i++) {
    int percent = (i * 100) / total_steps;
    progress_one_line(percent);

    // get callback interval
    int interval = callback();

    sleep(interval);
  }
  printf("\n");
}

// callback function example
int dynamic_seconds() {
  time_t now = time(NULL);
  int sec = now % 5 + 1; // (1 - 5s)
  print_wait(sec);
  return sec;
}

int main() {
  printf("\nstart example by sleep 1s interval...\n");

  int count = 0;
  for (int i = 0; i <= 5; i++) {
    progress_one_line(i);
    print_wait(1);
    sleep(1);
    count++;
  }
  if (count < 100) { // go to end
    progress_one_line(99);
    print_wait(1);
    sleep(1);
    progress_one_line(100);
    print_wait(1);
    sleep(1);
  }
  printf("\nDone!\n");

  printf("\nstart example by sleep dynamic_seconds interval\n");
  progress_with_callback(dynamic_seconds, 3);
  printf("\nDone!\n");

  return 0;
}