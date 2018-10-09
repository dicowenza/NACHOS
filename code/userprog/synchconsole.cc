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
	readAvail->P();
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
	if (s == NULL) return;
	char ch;
	int i;
	for (i = 0; i < n-1; i++) {
		ch = (char)SynchGetChar();
		if (ch == EOF) break;
		s[i] = ch;
	}
	s[i] = END_STRING_CHAR;
}



#endif // CHANGED
