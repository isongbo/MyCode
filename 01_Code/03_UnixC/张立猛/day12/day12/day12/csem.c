#include <stdio.h>
#include <errno.h>
#include <sys/sem.h>
// 打印菜单
int pmenu (void) {
	printf ("------------------\n");
	printf ("    迷你图书馆\n");
	printf ("------------------\n");
	printf ("[1] 借《三国演义》\n");
	printf ("[2] 还《三国演义》\n");
	printf ("[3] 借《水浒传》\n");
	printf ("[4] 还《水浒传》\n");
	printf ("[5] 借《红楼梦》\n");
	printf ("[6] 还《红楼梦》\n");
	printf ("[7] 借《西游记》\n");
	printf ("[8] 还《西游记》\n");
	printf ("[0] 退出\n");
	printf ("------------------\n");
	printf ("请选择：");
	int sel = -1;
	scanf ("%d", &sel);
	return sel;
}
// 打印剩余书数
int pleft (int semid,
	unsigned short semnum) {
	int val = semctl (semid, semnum,
		GETVAL);
	if (val == -1) {
		perror ("semctl");
		return -1;
	}
	printf ("还剩%d册。\n", val);
	return 0;
}
// 借书
int borrow (int semid,
	unsigned short semnum) {
	printf ("请稍候...\n");
//	struct sembuf sops = {semnum, -1, 0};
	struct sembuf sops = {semnum, -1,
		IPC_NOWAIT};
	if (semop (semid, &sops, 1) == -1) {
		if (errno != EAGAIN) {
			perror ("semop");
			return -1;
		}
		printf("暂时无书，下回再试。\n");
		return 0;
	}
	printf ("借阅成功！\n");
	return pleft (semid, semnum);
}
// 还书
int revert (int semid,
	unsigned short semnum) {
	struct sembuf sops = {semnum, 1, 0};
	if (semop (semid, &sops, 1) == -1) {
		perror ("semop");
		return -1;
	}
	printf ("还书成功！\n");
	return pleft (semid, semnum);
}
int main (void) {
	printf ("创建信号量...\n");
	key_t key = ftok (".", 100);
	if (key == -1) {
		perror ("ftok");
		return -1;
	}
	int semid = semget (key, 4,
		0644 | IPC_CREAT | IPC_EXCL);
	if (semid == -1) {
		perror ("semget");
		return -1;
	}
	printf ("初始化信号量...\n");
	unsigned short semarr[] = {5,5,5,5};
	if (semctl (semid, 0, SETALL,
		semarr) == -1) {
		perror ("semctl");
		return -1;
	}
	// 菜单循环
	int quit = 0;
	while (! quit) {
		int sel = pmenu ();
		switch (sel) {
			case 0:
				quit = 1;
				break;
			case 1: // 0
			case 3: // 1
			case 5: // 2
			case 7: // 3
				if (borrow (semid,
					sel / 2) == -1)
					return -1;
				break;
			case 2: // 0
			case 4: // 1
			case 6: // 2
			case 8: // 3
				if (revert (semid,
					(sel - 1) / 2) == -1)
					return -1;
				break;
			default:
				printf ("无效选择！\n");
				scanf ("%*[^\n]");
				scanf ("%*c");
				break;
		}
	}
	printf ("销毁信号量...\n");
	if (semctl (semid, 0, IPC_RMID)==-1){
		perror ("semctl");
		return -1;
	}
	printf ("完成！\n");
	return 0;
}
