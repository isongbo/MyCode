#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
void* thread_proc (void* arg) {
	int i;
	for (i = 0; i < 200; ++i) {
		putchar (*(char*)arg);
		sync ();
		int j;
		for (j = 0; j < 10000000; ++j);
	}
	return NULL;
}
int main (void) {
	setbuf (stdout, NULL);
	pthread_attr_t attr;
	pthread_attr_init (&attr);
	pthread_attr_setinheritsched (&attr,
		PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setschedpolicy (&attr, SCHED_RR);
	struct sched_param schedparam;
	schedparam.sched_priority =
		sched_get_priority_max (SCHED_RR);
	pthread_attr_setschedparam (&attr, &schedparam);
	pthread_t quick;
	int error = pthread_create (&quick, &attr,
		thread_proc, "+");
	if (error) {
		printf ("pthread_create: %s\n",
			strerror (error));
		return -1;
	}
	pthread_attr_destroy (&attr);
	pthread_t slow;
	pthread_create (&slow, NULL, thread_proc, "-");
	pthread_join (quick, NULL);
	pthread_join (slow, NULL);
	printf ("\n");
	return 0;
}
