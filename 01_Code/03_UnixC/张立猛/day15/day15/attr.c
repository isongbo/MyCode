#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void printattrs (pthread_attr_t* attr) {
	printf ("-------- 线程属性 --------\n");
	int detachstate;
	pthread_attr_getdetachstate (attr,
		&detachstate);
	printf ("分离状态：  %s\n",
		(detachstate == PTHREAD_CREATE_DETACHED) ?
			"分离线程" :
		(detachstate == PTHREAD_CREATE_JOINABLE) ?
			"可汇合线程" : "未知");
	int scope;
	pthread_attr_getscope (attr, &scope);
	printf ("竞争范围：  %s\n",
		(scope == PTHREAD_SCOPE_SYSTEM) ?
			"系统级竞争" :
		(scope == PTHREAD_SCOPE_PROCESS) ?
			"进程级竞争" : "未知");
	int inheritsched;
	pthread_attr_getinheritsched (attr,
		&inheritsched);
	printf ("继承特性：  %s\n",
		(inheritsched == PTHREAD_INHERIT_SCHED) ?
			"继承调度属性" :
		(inheritsched == PTHREAD_EXPLICIT_SCHED) ?
			"指定调度属性" : "未知");
	int schedpolicy;
	pthread_attr_getschedpolicy (attr,
		&schedpolicy);
	printf ("调度策略：  %s\n",
		(schedpolicy == SCHED_OTHER) ? "普通" :
		(schedpolicy == SCHED_FIFO) ? "先进先出" :
		(schedpolicy == SCHED_RR) ? "轮转" : "未知");
	struct sched_param schedparam;
	pthread_attr_getschedparam (attr,
		&schedparam);
	printf ("调度优先级：%d\n",
		schedparam.sched_priority);
	size_t guardsize;
	pthread_attr_getguardsize (attr,
		&guardsize);
	printf ("栈尾警戒区：%u字节\n", guardsize);
	void* stackaddr;
	size_t stacksize;
	pthread_attr_getstack (attr, &stackaddr,
		&stacksize);
	printf ("栈地址：    %p\n", stackaddr);
	printf ("栈大小：    %u字节\n", stacksize);
	printf ("--------------------------\n");
}
void* thread_proc (void* arg) {
	pthread_attr_t attr;
	pthread_getattr_np (pthread_self (), &attr);
	printattrs (&attr);
	exit (0);
	return NULL;
}
int main (void) {
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate (&attr,
		PTHREAD_CREATE_DETACHED);
	/*
	pthread_attr_setinheritsched (&attr,
		PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setschedpolicy (&attr, SCHED_FIFO);
	struct sched_param sp;
	sp.sched_priority = sched_get_priority_max (
		SCHED_FIFO);
	pthread_attr_setschedparam (&attr, &sp);
	*/
	pthread_attr_setstacksize (&attr, 32*1024*1024);
	pthread_create (&tid, &attr, thread_proc, NULL);
	pthread_attr_destroy (&attr);
	pause ();
	return 0;
}
