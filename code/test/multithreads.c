#ifdef CHANGED

#include "syscall.h"

#define N 10

/**
 * Print the number of the thread (== the given arg).
 */
void f(void *arg) {
    int x = *((int *)arg);
    PutString("Thread N°");
    PutInt(x);
    PutString("\n");
    ThreadExit();
}

int main() {
    int n;
    void *arg;
    for(n = 0; n < N; n++) {
        arg = &n;
        ThreadCreate(f, arg);
    }
    ThreadExit();
}

#endif