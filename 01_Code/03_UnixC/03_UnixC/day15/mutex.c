#include <stdio.h>
#include <pthread.h>
unsigned int g = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
void* foo (void* arg) {
	unsigned int i;
	pthread_mutex_lock (&m);
	for (i = 0; i < 100000000; ++i) {
//		pthread_mutex_lock (&m);
		++g;
//		pthread_mutex_unlock (&m);
	}
	pthread_mutex_unlock (&m);
	return NULL;
}
int main (void) {
	pthread_t tid1, tid2;
	pthread_create (&tid1, NULL, foo, NULL);
	pthread_create (&tid2, NULL, foo, NULL);
	pthread_join (tid1, NULL);
	pthread_join (tid2, NULL);
	printf ("g = %u\n", g);
	return 0;
}
