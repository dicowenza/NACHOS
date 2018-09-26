    #ifdef CHANGED


    #include "copyright.h"

    #include "system.h"

    #include "synchconsole.h"

    #include "synch.h"


    static Semaphore * readAvail;

    static Semaphore * writeDone;


    static void ReadAvailHandler(void * arg)

    {

      readAvail->V();

    }

    static void WriteDoneHandler(void * arg) {

      writeDone->V();

    }


    SynchConsole::SynchConsole(const char * in, const char *out)

    {

      readAvail = new Semaphore("read avail", 0);

      writeDone = new Semaphore("write done", 0);

      console = new console(in,out,readAvail,writeDone,0);

    }


    SynchConsole::~SynchConsole()

    {

      delete console;

      delete writeDone;

      delete readAvail;

    }


    void SynchConsole::SynchPutChar(int ch)

    {

      //On ecrit le caractere

      console->putchar(ch);

      //on attend que l'ecriture se termine

      writeDone->P();

      return NULL;

    }


    int SynchConsole::SynchGetChar()

    {

      int ch;

      //on attend qu'il y ai quelque chose à lire

      readAvail->P();

      //on recupere le caractere à lire

      ch=(int)console->getchar();

      

      return ch;

    }

    void SynchConsole::SynchPutString(const char s[])

    {

    // ...

    }

    void SynchConsole::SynchGetString(char * s, int n)

    {

    // ...

    }

    #endif // CHANGED