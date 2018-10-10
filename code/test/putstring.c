#ifdef CHANGED

#include "syscall.h"

int main() {
    int c;
    char str[100];

    PutString("Veuillez entrer un caractère: \n");
    c = GetChar();
    PutString("Le caractere saisie est :");
    PutChar(c);
    PutString("\n");
    PutString("Veuillez entrer une str: \n");
    GetString(str, 10);
    return 0;
}

#endif
