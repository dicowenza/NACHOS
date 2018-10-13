#ifdef CHANGED

#include "syscall.h"

int main() {
    char str[100];
    PutString("1. Veuillez entrer une chaine de caractère\n");
    GetString(str, 40);
    PutString("\n2. La chaine de caractere saisie est :");
    PutString(str);
    PutString("\n");

    // Test putstring alphabet (MAX_STRING_SIZE = 10)
    // PutString("abcdefghijklmnopqrstuvwxyz\n");
    return 0;
}

#endif