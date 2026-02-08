#include <stdio.h>

/*
 * return_type (*pointer_name)(parameter_types);
 * example:
 * int (*return_int)(void);
 * int (*return_int)(int);
 */

typedef int (*TakeIntReturnInt)(int);

typedef int (*ReturnNewInt)(TakeIntReturnInt take_int_return_int);

int return_int(int x) { return x; }

// Function to call the function pointer
// the first parameter is the function pointer
// the second parameter is the argument to pass to the function pointer
int return_intV2(int (*take_int_return_int)(int), int x) {
  return take_int_return_int(x);
}

int return_new_int(TakeIntReturnInt take_int_return_int) {
  return take_int_return_int(200);
}

// Function pointer for return void type
typedef void (*call_message)(char *message);

void print_message(char *message) { printf("%s\n", message); }

// Function to call the function pointer
void call_message_func(call_message func, char *message) { func(message); }

// example for callback function pointer
void log_info(char *msg) { printf("[INFO]  %s\n", msg); }
void log_error(char *msg) { printf("[ERROR] %s\n", msg); }

// Function that takes two function pointers as parameters for success and
// failure cases
void do_something(int success, call_message on_success, call_message on_fail) {
  if (success)
    on_success("success");
  else
    on_fail("failure");
}

int main() {

  TakeIntReturnInt func_ptr = return_int;

  ReturnNewInt return_new_int_ptr = return_new_int;

  printf("function return int: %d\n", func_ptr(100));

  printf("function return new int: %d\n", return_new_int_ptr(func_ptr));

  call_message_func(print_message, "Hello, Function Pointer!");
  do_something(1, log_info, log_error); // success case
  do_something(0, log_info, log_error); // failure case

  return 0;
}