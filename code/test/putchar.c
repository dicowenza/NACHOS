#ifdef CHANGED

#include "syscall.h"
void print(char c, int n)
{
  int i;
  #if 1

  for (i = 0; i < n; i++) {
    PutChar(c + i);
  }
  PutChar('\n');

  #endif
}

int main()
{
  print('a',4);
  // Exit(1);
}

#endif
