#ifdef CHANGED

#include "syscall.h"

/**
 * Print the 10 next number of (int)arg.
 */
void f(void *arg) {
    int i, y;
    y = (int)arg;
    PutString("We are in the thread t\n");
    i = (int)arg;
    for (i = 0; i < y+10; i++) {
        PutInt(i);
        PutString("\n");
    }
}

int main() {
    int x = 5;
    void *arg = &x;
	int t = ThreadCreate(f, arg);
    ThreadExit(t);
	return 0;
}

#endif
