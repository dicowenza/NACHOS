#ifdef CHANGED
#ifndef USERTHREAD_H
#define USERTHREAD_H

typedef struct ThreadArgs {
	int f;
	int arg;
} ThreadArgs;

extern int do_ThreadCreate(int f, int arg);
extern void do_ThreadExit();

#endif
#endif
