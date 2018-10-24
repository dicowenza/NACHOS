
#ifdef CHANGED

#include "userthread.h"
#include "thread.h"
#include "addrspace.h"
#include "system.h"
#include "synch.h"




static void StartUserThread (void *schmurtz);
static int cptThread = 0;

int do_ThreadCreate (int f,void * arg){
	cptThread++;
	DEBUG ('x', "[DEBUG] cptThread: %d\n", cptThread);
	schmurtz *s= (schmurtz *)malloc (sizeof (schmurtz));
	s->f = f;
	s->arg = arg;
	Thread *newThread = new Thread ("nouveauThread");
	newThread->Start (StartUserThread, s);
	return 0;
}

static void StartUserThread (void * structure){

  for (int i = 0; i < NumTotalRegs; i++){
		 machine->WriteRegister (i, 0);
	}

  schmurtz* s= (schmurtz*) structure;

  int stacktopAdress = currentThread->space->AllocateUserStack(cptThread);

	machine->WriteRegister (PCReg, s->f);
	DEBUG ('x', "[DEBUG] Function: %d\n", s->f);

	// machine->WriteRegister (4, 0);
	// DEBUG ('x', "[DEBUG] Arg: %d\n", s->arg);

	machine->WriteRegister (NextPCReg, machine->ReadRegister(PCReg) + 4);
	DEBUG ('x', "[DEBUG] NextPCReg: %d\n", machine->ReadRegister(PCReg) + 4);

	machine->WriteRegister (StackReg, stacktopAdress);
	DEBUG ('x', "[DEBUG] Adress: %d\n", stacktopAdress);

	machine->Run ();
	free (structure);
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
