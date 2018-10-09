#ifdef CHANGED

#include "syscall.h"

void print(char c, int n) {
	int i;
	for (i = 0; i < n; i++)
		PutChar(c + i);
	PutChar('\n');
	PutString("Bonjour\n");
}

void get() {
	int c;
	PutString("Saisir un char : ");
	c = GetChar();
	PutChar('\n');
	PutString("Le char saisit est : ");
	PutChar((char)c);
	PutChar('\n');
}

int main() {
	print('a', 4);
	get();
	Exit(1);
}

#endif
