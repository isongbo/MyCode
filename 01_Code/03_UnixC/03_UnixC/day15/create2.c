#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
void* thread_proc (void* arg) {
//	pthread_detach (pthread_self ());
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
	pthread_detach (tid);
	int error = pthread_join (tid, NULL);
	printf ("%s\n", strerror (error));
	int i;
	for (i = 0; i < 100; ++i) {
		printf ("-");
		usleep (100000);
	}
	getchar ();
	return 0;
}
