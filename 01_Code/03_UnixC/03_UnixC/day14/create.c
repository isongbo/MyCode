#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
void* thread_proc (void* arg) {
	printf ("我的ID：%lu\n",
		pthread_self ());
	printf ("我的参数：%s\n", (char*)arg);
	return NULL;
}
int main (void) {
	printf ("主线程调用了main函数\n");
	pthread_t tid;
	int error = pthread_create (&tid, NULL,
		thread_proc, "我是子线程");
	if (error) {
		printf ("pthread_create: %s\n",
			strerror (error));
		return -1;
	}
	printf ("子线程ID：%lu\n", tid);
	sleep (1);
	return 0;
}
