#ifdef CHANGED

#include "syscall.h"
#define N 5 // Nb of created threads.

/**
 * Print the number of the thread (i.e. the given arg).
 */
void f(void *arg) {
    int x = *((int *)arg);
    PutString("\nThread N°");
    PutInt(x);
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