#ifdef CHANGED

#include "syscall.h"

void print(char c, int n) {
	// ----- PutChar
	int i;
	for (i = 0; i < n; i++)
		PutChar(c + i);
	PutChar('\n');
	// ----- PutString
	PutString("Bonjour\n");
}

void get() {
	int c;
	char str[100];

	// ----- GetChar
	PutString("Saisir un char : ");
	c = GetChar();
	PutString("Le char saisit est : ");
	PutChar((char)c);

	// ----- GetString
	PutString("\nSaisir une str (10 char max.) : ");
	GetString(str, 10);
	PutString("La str saisit est : ");
	PutString(str);
}

int main() {
	print('a', 4);
	get();
	// Exit(1);
	return 0;
}

#endif
