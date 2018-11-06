#ifdef CHANGED
#ifndef USERTHREAD_H
#define USERTHREAD_H

typedef struct ThreadArgs {
	int f;
	void *arg;
} ThreadArgs;

extern void do_ThreadCreate(int f, void* arg);
extern void do_ThreadExit();

#endif
#endif
