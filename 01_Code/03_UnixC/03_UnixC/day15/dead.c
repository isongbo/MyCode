#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t a = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t b = PTHREAD_MUTEX_INITIALIZER;
void* thread1 (void* arg) {
	pthread_t tid = pthread_self ();
	printf ("%lu线程等待a\n", tid);
	pthread_mutex_lock (&a);
	printf ("%lu线程获得a\n", tid);
	sleep (1);
	printf ("%lu线程等待b\n", tid);
	pthread_mutex_lock (&b);
	printf ("%lu线程获得b\n", tid);
	pthread_mutex_unlock (&b);
	printf ("%lu线程释放b\n", tid);
	pthread_mutex_unlock (&a);
	printf ("%lu线程释放a\n", tid);
}
void* thread2 (void* arg) {
	pthread_t tid = pthread_self ();
	printf ("%lu线程等待b\n", tid);
	pthread_mutex_lock (&b);
	printf ("%lu线程获得b\n", tid);
	sleep (1);
	printf ("%lu线程等待a\n", tid);
	pthread_mutex_lock (&a);
	printf ("%lu线程获得a\n", tid);
	pthread_mutex_unlock (&a);
	printf ("%lu线程释放a\n", tid);
	pthread_mutex_unlock (&b);
	printf ("%lu线程释放b\n", tid);
}
int main (void) {
	pthread_t tid1, tid2;
	pthread_create (&tid1, NULL,thread1,NULL);
	pthread_create (&tid2, NULL,thread2,NULL);
	pthread_join (tid1, NULL);
	pthread_join (tid2, NULL);
	return 0;
}
