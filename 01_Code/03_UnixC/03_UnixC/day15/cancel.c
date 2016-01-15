#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
void elapse (void) {
	unsigned int i;
	for (i = 0; i < 800000000; ++i);
}
void* thread_proc (void* arg) {
	pthread_setcancelstate (
		PTHREAD_CANCEL_DISABLE, NULL);
	pthread_setcancelstate (
		PTHREAD_CANCEL_ENABLE, NULL);
	pthread_setcanceltype (
		PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
	pthread_setcanceltype (
		PTHREAD_CANCEL_DEFERRED, NULL);
	for (;;) {
		printf ("子线程正在运行\n");
		elapse ();
	}
	return NULL;
}
int main (void) {
	setbuf (stdout, NULL);
	pthread_t tid;
	pthread_create (&tid, NULL, thread_proc,
		NULL);
	getchar ();
	int error = pthread_cancel (tid);
	if (error) {
		printf ("pthread_cancel: %s\n",
			strerror (error));
		return -1;
	}
	printf ("pthread_cancel函数已返回\n");
	pthread_join (tid, NULL);
	printf ("子线程已终止\n");
	return 0;
}
