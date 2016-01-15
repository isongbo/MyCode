#include <stdio.h>
#include <string.h>
#include <pthread.h>
unsigned int g_cn = 0;
void* thread_proc (void* arg) {
	unsigned int i;
	for (i = 0; i < 100000000; ++i)
		++g_cn;
	return NULL;
}
int main (void) {
	pthread_t t1, t2;
	pthread_create (&t1, NULL, thread_proc, NULL);
	pthread_create (&t2, NULL, thread_proc, NULL);
	pthread_join (t1, NULL);
	pthread_join (t2, NULL);
	printf ("g_cn = %u\n", g_cn); // ?
	return 0;
}
