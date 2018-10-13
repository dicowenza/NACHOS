#ifdef CHANGED

#include "syscall.h"

int main() {
    int c;
    char str[100];

    PutString("Veuillez entrer un caractère: \n");
    c = GetChar();
    PutString("Le caractere saisie est :");
    PutChar(c);
    PutChar('\n');
    return 0;
}

#endif