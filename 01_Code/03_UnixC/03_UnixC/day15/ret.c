#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
/*
double thread_area (double r) {
	double s = 3.14 * r * r;
	return s;
}
*/
void* thread_area (void* arg) {
	double r = *(double*)arg;
	/*
	static double s;
	s = 3.14 * r * r;
	return &s;
	*/
	double* p = (double*)malloc (
		sizeof (double));
	*p = 3.14 * r * r;
	return p;
}
int main (void) {
	/*
	double s = thread_area (10);
	printf ("圆面积：%g\n", s);
	*/
	double r = 10;
	pthread_t tid;
	pthread_create (&tid, NULL, thread_area,
		&r);
	sleep (5);
	double* p;
	pthread_join (tid, (void**)&p);
	printf ("圆面积：%g\n", *p);
	free (p);
	return 0;
}
