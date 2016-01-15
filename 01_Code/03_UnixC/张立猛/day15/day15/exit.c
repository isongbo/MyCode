#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define PAI 3.14159
void calc (double r) {
	double* s = malloc (sizeof (double));
	*s = PAI * r * r;
	pthread_exit (s);
}
void* area (void* arg) {
	double r = *(double*)arg;
	/*
	double* s = malloc (sizeof (double));
	*s = PAI * r * r;
	pthread_exit (s); // return s;
	*/
	calc (r);
	// 以下两行不被执行
//	*s = 2 * PAI * r;
//	return s;
	return NULL;
}
int main (void) {
	printf ("r = ");
	double r;
	scanf ("%lf", &r);
	pthread_t tid;
	pthread_create (&tid, NULL, area, &r);
	double* s;
	pthread_join (tid, (void**)&s);
	printf ("s = %g\n", *s);
	free (s);
	return 0;
}
