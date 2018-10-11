#ifdef CHANGED

#include "syscall.h"

int main() {
    char str[100];
    PutString("1. Get : ");
    GetString(str, 29);
    PutString("\n2. Put : ");
    PutString(str);
    PutString("\n");
    
    // Test putstring alphabet (MAX_STRING_SIZE = 10)
    // PutString("abcdefghijklmnopqrstuvwxyz\n");
    return 0;
}

#endif
