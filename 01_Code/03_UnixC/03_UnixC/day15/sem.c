#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
int seats = 5;
pthread_mutex_t m =
	PTHREAD_MUTEX_INITIALIZER;
sem_t s;
void* people (void* arg) {
	pthread_t tid = pthread_self ();
	sem_wait (&s);
	pthread_mutex_lock (&m);
	printf ("%lu坐下，还剩%d个空座\n",
		tid, --seats);
	pthread_mutex_unlock (&m);
	usleep (500000);
	pthread_mutex_lock (&m);
	printf ("%lu下车，还剩%d个空座\n",
		tid, ++seats);
	pthread_mutex_unlock (&m);
	sem_post (&s);
	return NULL;
}
int main (void) {
	sem_init (&s, 0, seats);
	printf ("发车时有%d个空座\n", seats);
	int i;
	pthread_t tids[20];
	for (i = 0; i < 20; ++i)
		pthread_create (&tids[i], NULL,
			people, NULL);
	for (i = 0; i < 20; ++i)
		pthread_join (tids[i], NULL);
	printf ("收车时有%d个空座\n", seats);
	sem_destroy (&s);
	return 0;
}
