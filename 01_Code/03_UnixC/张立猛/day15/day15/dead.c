#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t g_mtxa = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t g_mtxb = PTHREAD_MUTEX_INITIALIZER;
void* thread_proc1 (void* arg) {
	printf ("线程1：等待资源A...\n");
	pthread_mutex_lock (&g_mtxa);
	printf ("线程1：获得资源A！\n");
	sleep (1);
	printf ("线程1：等待资源B...\n");
	pthread_mutex_lock (&g_mtxb);
	printf ("线程1：获得资源B！\n");
	pthread_mutex_unlock (&g_mtxb);
	printf ("线程1：释放资源B。\n");
	pthread_mutex_unlock (&g_mtxa);
	printf ("线程1：释放资源A。\n");
}
void* thread_proc2 (void* arg) {
	printf ("线程2：等待资源B...\n");
	pthread_mutex_lock (&g_mtxb);
	printf ("线程2：获得资源B！\n");
	sleep (1);
	printf ("线程2：等待资源A...\n");
	pthread_mutex_lock (&g_mtxa);
	printf ("线程2：获得资源A！\n");
	pthread_mutex_unlock (&g_mtxa);
	printf ("线程2：释放资源A。\n");
	pthread_mutex_unlock (&g_mtxb);
	printf ("线程2：释放资源B。\n");
}
int main (void) {
	pthread_t t1, t2;
	pthread_create (&t1, NULL, thread_proc1, NULL);
	pthread_create (&t2, NULL, thread_proc2, NULL);
	pthread_join (t1, NULL);
	pthread_join (t2, NULL);
	return 0;
}
