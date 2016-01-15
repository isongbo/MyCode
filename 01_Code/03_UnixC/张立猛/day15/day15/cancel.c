#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void elapse (void) {
	size_t i;
	for (i = 0; i < 800000000; ++i);
}
void* thread_proc (void* arg) {
	/*
	pthread_setcancelstate (PTHREAD_CANCEL_DISABLE,
		NULL);
	*/
	pthread_setcanceltype (
		PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
	for (;;) {
		printf ("子在川上曰，逝者如斯夫。\n");
		elapse ();
	}
	return NULL;
}
int main (void) {
	setbuf (stdout, NULL);
	printf ("按<回车>取消线程...\n");
	pthread_t tid;
	pthread_create (&tid, NULL, thread_proc, NULL);
	getchar ();
	pthread_cancel (tid);
	printf ("已发送取消请求，等待线程终止...\n");
	pthread_join (tid, NULL);
	printf ("线程已终止。\n");
	return 0;
}
