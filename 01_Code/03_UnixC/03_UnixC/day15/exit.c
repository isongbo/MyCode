#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void* bar (void) {
	exit (0);
//	return;
	static int retval = 5678;
//	pthread_exit (&retval);
	return &retval;
}
void* foo (void* arg) {
	printf ("AAA\n");
	static int retval = 1234;
//	return &retval;
//	pthread_exit (&retval);
	bar ();
	printf ("BBB\n");
	return &retval;
}
int main (void) {
	pthread_t tid;
	pthread_create (&tid, NULL, foo, NULL);
	int* retval;
	pthread_join (tid, (void**)&retval);
	printf ("线程返回%d\n", *retval);
	return 0;
}
