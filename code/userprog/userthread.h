#ifdef CHANGED

#ifndef USERTHREAD_H
#define USERTHREAD_H

typedef struct schmurtz{
	int f;
	void * arg;
}schmurtz;


extern int do_ThreadCreate (int f, void* arg);
extern void do_ThreadExit ();

#endif

#endif
