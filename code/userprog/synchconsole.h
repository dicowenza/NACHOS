#ifdef CHANGED
#ifndef SYNCHCONSOLE_H
#define SYNCHCONSOLE_H
#include "copyright.h"
#include "utility.h"
#include "console.h"

class SynchConsole:dontcopythis {
	public:
		SynchConsole(const char *readFile, const char *writeFile); // initialize the hardware console device
		~SynchConsole();                    // clean up console emulation
		void SynchPutChar(int ch);          // Unix putchar(3S)
		int SynchGetChar();                 // Unix getchar(3S)
		void SynchPutString(const char *s);	// Unix fputs(3S)
		void SynchGetString(char *s, int n);// Unix fgets(3S)
	private:
		Console *console;
		const char END_STRING_CHAR = '\0';
};

#endif // SYNCHCONSOLE_H
#endif // CHANGED
