#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
int g_cn = 5;
pthread_mutex_t g_mtx;
sem_t g_sem;
void* thread_proc (void* arg) {
	/*
	sem_wait (&g_sem);
	*/
try_again:
	if (sem_trywait (&g_sem) == -1) {
		if (errno == EAGAIN) {
			printf ("%lu站着，继续等待...\n",
				pthread_self ());
			goto try_again;
		}
		return NULL;
	}
	pthread_mutex_lock (&g_mtx);
	printf ("%lu坐下，还剩%d个座位。\n",
		pthread_self (), --g_cn);
	pthread_mutex_unlock (&g_mtx);
	usleep (500000);
	pthread_mutex_lock (&g_mtx);
	printf ("%lu下车，还剩%d个座位。\n",
		pthread_self (), ++g_cn);
	pthread_mutex_unlock (&g_mtx);
	sem_post (&g_sem);
	return NULL;
}
int main (void) {
	size_t i;
	pthread_t tids[20];
	printf ("发车时共有%d个空座。\n", g_cn);
	pthread_mutex_init (&g_mtx, NULL);
	sem_init (&g_sem, 0, g_cn);
	for (i = 0; i < 20; ++i)
		pthread_create (&tids[i], NULL, thread_proc,
			NULL);
	for (i = 0; i < 20; ++i)
		pthread_join (tids[i], NULL);
	sem_destroy (&g_sem);
	pthread_mutex_destroy (&g_mtx);
	printf ("收车时共有%d个空座。\n", g_cn);
	return 0;
}
