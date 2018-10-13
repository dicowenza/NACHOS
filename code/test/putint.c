#ifdef CHANGED

#include "syscall.h"

void print(int start, int end) {
	int i;
    for (i = start; i < end; i++) {
        PutInt(i);
        PutString("\n");
    }
}

void get() {
    int n;
    PutString("Veuillez saisir un nombre entier [-2 147 483 648, 2 147 483 647] : ");
    n = GetInt();
    PutString("Vous avez saisit le nombre : ");
    PutInt(n);
    PutString("\n");
}

int main() {
	print(2147483645, 2147483647);
    print(-2147483647, -2147483645);
    // /!\ Be careful on the limits : (int)x est définit sur [-2 147 483 648, 2 147 483 647]
    get();
	return 0;
}

#endif
