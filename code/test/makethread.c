#ifdef CHANGED

#include "syscall.h"

/**
 * Print the given int arg.
 */
void f(void *arg) {
    int x = *((int *)arg);
    PutString("We are in the thread t\n");
    PutString("The given arg of thread t function is : ");
    PutInt(x);
    PutString("\n");
    ThreadExit();
}

int main() {
    int x = 5;
    void *arg = &x;
    PutString("Launch thread t from main\n");
	ThreadCreate(f, arg);
    PutString("We'll exit from main\n");
    ThreadExit();
}

#endif
