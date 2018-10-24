
#ifdef CHANGED

#include "userthread.h"
#include "thread.h"
#include "addrspace.h"
#include "system.h"
#include "synch.h"


typedef struct schmurtz{
	int f;
	void arg;
}schmurtz;

static void StartUserThread (void *schmurtz);
static int cptThread = 0;

int do_ThreadCreate (int f, int arg){
	cptThread++;
	DEBUG ('x', "[DEBUG] cptThread: %d\n", cptThread);
	schmurtz = (schmurtz *) malloc (sizeof schmurtz);
	s.f = f;
	s.arg = arg;
	Thread *newThread = new Thread ("nouveauThread");
	newThread->Start (StartUserThread, schmurtz);
	return 0;
}

static void StartUserThread (void *schmurtz){
  int i;
  for (i = 0; i < NumTotalRegs; i++)
	   machine->WriteRegister (i, 0);

  schmurtz s= (schmurtz)

  int stacktopAdress = currentThread->space->AllocateUserStack(cptThread);

	machine->WriteRegister (PCReg, f);
	DEBUG ('x', "[DEBUG] Function: %d\n", f);

	machine->WriteRegister (4, arg);
	DEBUG ('x', "[DEBUG] Arg: %d\n", arg);

	machine->WriteRegister (NextPCReg, machine->ReadRegister(PCReg) + 4);
	DEBUG ('x', "[DEBUG] NextPCReg: %d\n", machine->ReadRegister(PCReg) + 4);

	machine->WriteRegister (StackReg, stacktopAdress);
	DEBUG ('x', "[DEBUG] Adress: %d\n", stacktopAdress);

	machine->Run ();
	free (schmurtz);
}


void do_ThreadExit (){

	DEBUG ('x', "[DEBUG] cptThread Exit: %d\n", cptThread);

	if(cptThread > 0)
	{
		cptThread--;
	}
	else
	{
		interrupt->Halt();
	}
	currentThread->Finish ();
}



#endif // CHANGED
