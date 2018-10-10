#ifdef CHANGED

#include "syscall.h"

int main() {
    char str[100];
    PutString("1. Get : ");
    GetString(str, 13);
    PutString("\n2. Put : ");
    PutString(str);
    PutString("\n");
    
    // Test putstring alphabet
    PutString("abcdefghijklmnopqrstuvwxyz\n");
    return 0;
}

#endif
