#ifdef CHANGED

#include "syscall.h"
#define N 10 // Nb of created threads.

int test_inc = 0;

/**
 * Print the number of the thread (i.e. the given arg).
 */
void f(void *arg) {
    int x = *((int *)arg);
    test_inc++;
    PutString("Thread N°");
    PutInt(x);
    PutString("\n");
    ThreadExit();
}

int main() {
    int i;
    void* args[N];
    for(i = 0; i < N; i++) {
        args[i] = &i;
        ThreadCreate(f, args[i]);
    }
    ThreadExit();
    return 0;
}

#endif