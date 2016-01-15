#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void* thread_proc (void* arg) {
	int i;
	for (i = 0; i < 100; ++i) {
		printf ("+");
		usleep (100000);
	}
	return NULL;
}
int main (void) {
	setbuf (stdout, NULL);
	/*
	thread_proc (NULL);
	*/
	pthread_t tid;
	pthread_create (&tid, NULL, thread_proc,
		NULL);
	int i;
	for (i = 0; i < 100; ++i) {
		printf ("-");
		usleep (100000);
	}
	getchar ();
	return 0;
}
