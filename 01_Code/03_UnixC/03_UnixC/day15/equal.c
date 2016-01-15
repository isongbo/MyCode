#include <stdio.h>
#include <pthread.h>
pthread_t g_main;
void* foo (void* arg) {
	if (pthread_equal (pthread_self (),
		g_main))
		printf ("被主线程调用\n");
	else
		printf ("被子线程调用\n");
	return NULL;
}
int main (void) {
	g_main = pthread_self ();
	foo (NULL);
	pthread_t tid;
	pthread_create (&tid, NULL, foo, NULL);
	pthread_join (tid, NULL);
	return 0;
}
