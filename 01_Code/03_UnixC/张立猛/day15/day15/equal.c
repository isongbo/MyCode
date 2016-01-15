#include <stdio.h>
#include <string.h>
#include <pthread.h>
pthread_t g_main;
void* ismain (void* arg) {
	if (pthread_equal (pthread_self (), g_main))
		printf ("我是主线程！\n");
	else
		printf ("我是子线程！\n");
	return NULL;
}
int main (void) {
	g_main = pthread_self ();
	ismain (NULL);
	pthread_t tid;
	pthread_create (&tid, NULL, ismain, NULL);
	pthread_join (tid, NULL);
	return 0;
}
