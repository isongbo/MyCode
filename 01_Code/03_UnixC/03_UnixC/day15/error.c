#include <stdio.h>
#include <pthread.h>
unsigned int g = 0;
void* foo (void* arg) {
	unsigned int i;
	for (i = 0; i < 100000000; ++i)
		++g;
	return NULL;
}
int main (void) {
	/*
	foo (NULL);
	foo (NULL);
	*/
	pthread_t tid1, tid2;
	pthread_create (&tid1, NULL, foo, NULL);
	pthread_create (&tid2, NULL, foo, NULL);
	pthread_join (tid1, NULL);
	pthread_join (tid2, NULL);
	printf ("g = %u\n", g);
	return 0;
}
