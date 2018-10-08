#ifdef CHANGED
#include "copyright.h"
#include "system.h"
#include "synchconsole.h"
#include "synch.h"

static Semaphore *readAvail;
static Semaphore *writeDone;


static void ReadAvailHandler(void *arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void *arg) { (void) arg; writeDone->V(); }

SynchConsole::SynchConsole(const char *in, const char *out) {
	readAvail = new Semaphore("read avail", 0);
	writeDone = new Semaphore("write done", 0);
	console = new Console(in, out, ReadAvailHandler, WriteDoneHandler, 0);
}

SynchConsole::~SynchConsole() {
	delete console;
	delete writeDone;
	delete readAvail;
}

void SynchConsole::SynchPutChar(int ch) {
	console->PutChar(ch);
	writeDone->P();
}

int SynchConsole::SynchGetChar() {
	// On attend qu'il y ai quelque chose à lire
	readAvail->P();
	// On recupere le caractere à lire
	int ch = (int)console->GetChar();
	return ch;
}

void SynchConsole::SynchPutString(const char s[]) {
        int i = 0;
        while (s[i] != END_STRING_CHAR) {
                SynchPutChar((int)s[i]);
                i++;
        }
}

void SynchConsole::SynchGetString(char * s, int n) {
	char ch;
	int counter= 0;
	if(s == NULL)
		return;
// Tant qu'il y a des caractères et que la taille n'est pas atteinte
	while(counter < n-1 && (ch = (char)SynchGetChar()) != EOF && ch != '\n')
		{
			s[counter] = ch;
			counter++;
		}
		// pour marquer la fin de chaine
		s[counter] = '\0';

}



#endif // CHANGED
