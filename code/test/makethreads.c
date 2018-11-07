#ifdef CHANGED

#include "syscall.h"

/**
 * Print the 10 next number of (int)arg.
 */
void f(void *arg) {
    int i, y;
    y = (int)arg;
    PutString("We are in the thread t\n");
    for (i = y; i < y+10; i++) {
        PutInt(i);
        PutString("\n");
    }
}

int main() {
    int t, x = 5;
    void *arg = &x;
    PutString("Launch t thread from main\n");
	t = ThreadCreate(&f, arg);
    //ThreadExit();
	return 0;
}

#endif
