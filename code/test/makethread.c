#ifdef CHANGED

#include "syscall.h"

/**
 * Print the given int arg.
 */
void f(void *arg) {
    int x = *((int *)arg);
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
    while(1) ;
}

#endif
