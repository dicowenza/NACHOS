#ifdef CHANGED

#include "userthread.h"
#include "thread.h"
#include "addrspace.h"
#include "system.h"
#include "synch.h"

static void StartUserThread (void *argsStruct);
static int cptThread = 0;

void do_ThreadCreate (int f,void * arg) {
	DEBUG ('x', "[DEBUG] cptThread: %d\n", cptThread);
	cptThread++;
	
	ThreadArgs *TArgs = (ThreadArgs *) malloc(sizeof(ThreadArgs));
	TArgs->f = f;
	TArgs->arg = arg;

	Thread *newThread = new Thread("newThread");
	newThread->Start(StartUserThread, TArgs);
}

static void StartUserThread(void *argsStruct) {

	for(int i = 0; i < NumTotalRegs; i++) {
		machine->WriteRegister(i, 0);
	}

	ThreadArgs* TArgs = (ThreadArgs*) argsStruct;
	int stacktopAdress = currentThread->space->AllocateUserStack(cptThread);

	machine->WriteRegister (PCReg, TArgs->f);
	DEBUG ('x', "[DEBUG] Function: %d\n", TArgs->f);
	// machine->WriteRegister (4, 0); // Need to write something in arg register ?
	machine->WriteRegister (NextPCReg, machine->ReadRegister(PCReg) + 4);
	DEBUG ('x', "[DEBUG] NextPCReg: %d\n", machine->ReadRegister(PCReg) + 4);
	machine->WriteRegister (StackReg, stacktopAdress);
	DEBUG('x', "[DEBUG] Adress: %d\n", stacktopAdress);

	machine->Run();
	free(argsStruct);
}


void do_ThreadExit() {
	DEBUG ('x', "[DEBUG] cptThread Exit: %d\n", cptThread);
	if(cptThread > 0) {
		cptThread--;
	} else {
		interrupt->Halt();
	}
	currentThread->Finish ();
}



#endif // CHANGED
