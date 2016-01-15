#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>
#include "../inc/bank.h"
static int g_reqid = -1; // 请求消息队列
static int g_resid = -1; // 响应消息队列
// 菜单循环
void menu_loop (int (*menu) (void),
	int (*on_menu[]) (void),size_t size){
	for (;;) {
		int id = menu ();
		if (id < 0 || size <= id)
			printf ("无效选择！\n");
		else if (on_menu[id] () == -1)
			break;
	}
}
// 主菜单
int main_menu (void) {
	printf ("--------\n");
	printf ("本地银行\n");
	printf ("--------\n");
	printf ("[1] 开户\n");
	printf ("[2] 清户\n");
	printf ("[3] 存款\n");
	printf ("[4] 取款\n");
	printf ("[5] 查询\n");
	printf ("[6] 转帐\n");
	printf ("[0] 退出\n");
	printf ("--------\n");
	printf ("请选择：");
	int id = -1;
	scanf ("%d", &id);
	scanf ("%*[^\n]");
	scanf ("%*c");
	return id;
}
// 退出
int on_quit (void) {
	printf ("谢谢使用，再见！\n");
	return -1;
}
// 开户
int on_open (void) {
	pid_t pid = getpid ();
	OPEN_REQUEST req = {TYPE_OPEN, pid};
	printf ("户名：");
	scanf ("%s", req.name);
	printf ("密码：");
	scanf ("%s", req.passwd);
	printf ("金额：");
	scanf ("%lf", &req.balance);
	if (msgsnd (g_reqid, &req,
		sizeof(req)-sizeof(req.type),
		0) == -1) {
		perror ("msgsnd");
		return 0;
	}
	OPEN_RESPOND res;
	if (msgrcv (g_resid, &res,
		sizeof(res)-sizeof(res.type),
		pid, 0) == -1) {
		perror ("msgrcv");
		return 0;
	}
	if (strlen (res.error)) {
		printf ("%s\n", res.error);
		return 0;
	}
	printf ("帐号：%d\n", res.id);
	return 0;
}
// 清户
int on_close (void) {
	printf ("处理清户交易...\n");
	return 0;
}
// 存款
int on_save (void) {
	printf ("处理存款交易...\n");
	return 0;
}
// 取款
int on_withdraw (void) {
	printf ("处理取款交易...\n");
	return 0;
}
// 查询
int on_query (void) {
	pid_t pid = getpid ();
	QUERY_REQUEST req = {TYPE_QUERY,pid};
	printf ("帐号：");
	scanf ("%d", &req.id);
	printf ("户名：");
	scanf ("%s", req.name);
	printf ("密码：");
	scanf ("%s", req.passwd);
	if (msgsnd (g_reqid, &req,
		sizeof(req)-sizeof(req.type),
		0) == -1) {
		perror ("msgsnd");
		return 0;
	}
	QUERY_RESPOND res;
	if (msgrcv (g_resid, &res,
		sizeof(res)-sizeof(res.type),
		pid, 0) == -1) {
		perror ("msgrcv");
		return 0;
	}
	if (strlen (res.error)) {
		printf ("%s\n", res.error);
		return 0;
	}
	printf ("余额：%.2lf\n",res.balance);
	return 0;
}
// 转帐
int on_transfer (void) {
	printf ("处理转帐交易...\n");
	return 0;
}
int main (void) {
	// 获取请求消息队列
	if ((g_reqid = msgget (KEY_REQUEST,
		0)) == -1) {
		perror ("msgget");
		return -1;
	}
	// 获取响应消息队列
	if ((g_resid = msgget (KEY_RESPOND,
		0)) == -1) {
		perror ("msgget");
		return -1;
	}
	// 主菜单循环
	int (*on_menu[]) (void) = {
		on_quit,
		on_open,
		on_close,
		on_save,
		on_withdraw,
		on_query,
		on_transfer};
	menu_loop (main_menu, on_menu,
		sizeof (on_menu) /
		sizeof (on_menu[0]));
	return 0;
}
