#ifdef CHANGED
#include "copyright.h"
#include "system.h"
#include "synchconsole.h"
#include "synch.h"

static Semaphore *readAvail;
static Semaphore *writeDone;

static Semaphore *mutex_getChar;
static Semaphore *mutex_putChar;

static void ReadAvailHandler(void *arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void *arg) { (void) arg; writeDone->V(); }

SynchConsole::SynchConsole(const char *in, const char *out) {
	readAvail = new Semaphore("read avail", 0);
	writeDone = new Semaphore("write done", 0);
	console = new Console(in, out, ReadAvailHandler, WriteDoneHandler, 0);
	mutex_getChar = new Semaphore("PutChar", 1);
	mutex_putChar = new Semaphore("GetChar", 1);
}

SynchConsole::~SynchConsole() {
	delete console;
	delete writeDone;
	delete readAvail;
}

void SynchConsole::SynchPutChar(int ch) {
	mutex_putChar->P();
	console->PutChar(ch);
	writeDone->P();
	mutex_putChar->V();
}

int SynchConsole::SynchGetChar() {
	mutex_getChar->P();
	readAvail->P();
	int ch = (int)console->GetChar();
	mutex_getChar->V();
	return ch;
}

void SynchConsole::SynchPutString(const char s[]) {
	int i = 0;
	while (s[i] != END_STRING_CHAR) {
		SynchPutChar((int)s[i]);
		i++;
	}
}

void SynchConsole::SynchGetString(char *s, int n) {
	if (s == NULL) return;
	char ch;
	int i;
	for (i = 0; i < n-1; i++) {
		ch = (char)SynchGetChar();
		if (ch == EOF || ch == '\n') break;
		s[i] = ch;
	}
	s[i] = END_STRING_CHAR;
}

void SynchConsole::SynchPutInt(int n) {
	char *buffer = new char[INT_MAX_DIGIT];
	snprintf(buffer, INT_MAX_DIGIT, "%d", n);
	SynchPutString(buffer);
	delete[] buffer;
}

int SynchConsole::SynchGetInt() {
	int n;
	char *buffer = new char[INT_MAX_DIGIT];
	SynchGetString(buffer, INT_MAX_DIGIT);
	sscanf(buffer, "%d", &n);
	delete[] buffer;
	return n;
}



#endif // CHANGED
