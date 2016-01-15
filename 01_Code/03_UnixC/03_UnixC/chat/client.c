//聊天室客户端
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>
//准备工作
int sockfd;//客户端socket
char *IP = "127.0.0.1";//本地IP
short PORT = 10222;//服务器服务端口
typedef struct sockaddr SA;
char name[30];//存放聊天昵称
//1启动客户端，连接服务器
void init(){
	printf("客户端开始启动\n");
	sockfd = socket(PF_INET,SOCK_STREAM,0);
	struct sockaddr_in addr;
	addr.sin_family = PF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(IP);
	if(connect(sockfd,(SA*)&addr,sizeof(addr)) == -1){
		perror("无法连接到服务器");
		printf("客户端启动失败\n");
		exit(-1);
	}
	printf("客户端启动成功\n");
}
//2通信
void start(){
	//发消息之前，启动线程接受服务器发过来的消息
	pthread_t pid;
	void* recv_thread(void*);//函数声明
	pthread_create(&pid,0,recv_thread,0);
	while(1){
		char buf[100] = {};
		scanf("%s",buf);//读取客户端的输入
		char msg[100] = {};
		sprintf(msg,"%s 说: %s",name,buf);
		send(sockfd,msg,strlen(msg),0);//发送消息给服务器
	}
}
void* recv_thread(void *p){
	while(1){
		char buf[100] = {};
		if(recv(sockfd,buf,sizeof(buf),0)<=0){
			return;//出错就结束线程
		}
		printf("%s\n",buf);//输出接收到的内容
	}
}
void sig_close(){
	//关闭客户端的socket
	close(sockfd);
	exit(0);
}
int main(){
	signal(SIGINT,sig_close);//善后工作
	printf("请输入您的昵称:");
	scanf("%s",name);
	init();//连接服务器
	send(sockfd,name,strlen(name),0);
	start();//通信
	return 0;
}
