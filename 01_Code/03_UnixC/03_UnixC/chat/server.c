//聊天室服务器端
#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
//一些准备工作
struct client{
	char name[30];//客户端连接上来时，发过来的名字
	int fds;//标志客户端的socket描述符
};
struct client c[100] = {0};//最多记录100个客户端
int sockfd;//服务器的socket
int size;//标记数组的下标
char *IP = "127.0.0.1";//获取本机IP，回送地址
short PORT = 10222;//端口号
typedef struct sockaddr SA;//用作通信地址类型转换

//1初始化服务器的网络
void init(){
	printf("聊天室服务器开始启动..\n");
	//创建socket
	sockfd = socket(PF_INET,SOCK_STREAM,0);
	if(sockfd == -1){
		perror("创建socket失败");
		printf("服务器启动失败\n");
		exit(-1);
	}
	//准备通信地址
	struct sockaddr_in addr;//网络通信地址结构
	addr.sin_family = PF_INET;//协议簇
	addr.sin_port = htons(PORT);//端口
	addr.sin_addr.s_addr = inet_addr(IP);//IP地址
	//绑定socket和通信地址
	if(bind(sockfd,(SA*)&addr,sizeof(addr)) == -1){
		perror("绑定失败");
		printf("服务器启动失败\n");
		exit(-1);
	}
	printf("成功绑定\n");
	//设置监听
	if(listen(sockfd,100) == -1){
		perror("设置监听失败");
		printf("服务器启动失败\n");
		exit(-1);
	}
	printf("设置监听成功\n");
	printf("初始化服务器成功\n");
	//等待客户端连接(写到另一个函数中)
}
//分发消息函数
void sendMsgToAll(char *msg){
	int i = 0;
	for(;i<size;i++){
		printf("sendto%d\n",c[i].fds);
		send(c[i].fds,msg,strlen(msg),0);
	}
}
//线程函数中进行通信
//主要是接受客户端的消息，把消息分发给所有客户端
void * service_thread(void *p){
	char name[30] = {};
	if(recv(c[size].fds,name,sizeof(name),0)>0){
		//接收到客户端的昵称
		strcpy(c[size].name,name);
	}
	size++;
	//先群发一条提示，告诉所有客户端某某进入聊天室
	char tishi[100] = {};
	sprintf(tishi,"热烈欢迎 %s 进入本聊天室\n",c[size-1].name);
	//用来群发消息的函数
	sendMsgToAll(tishi);
	int fd = *(int*)p;
	printf("pthread = %d\n",fd);
	//通信，接收消息，分发消息
	while(1){
		char buf[100] = {};
		if(recv(fd,buf,sizeof(buf),0) == 0){
			//返回0表示客户端退出连接
			printf("fd = %dquit\n",fd);//test
			//清除这个客户端在数组中的信息
			int i,j;
			char name[20] = {};
			int flag = 1;//开关标志
			for(i=0;i<size;i++){
				if(c[i].fds == fd){
					strcpy(name,c[i].name);//记录要删除客户端的昵称
					i++;//防止数组溢出
					flag = 0;
				}
				if(flag!=1){
					c[i-1].fds = c[i].fds;//覆盖
					strcpy(c[i-1].name,c[i].name);
				}
			}
			c[i].fds = 0;//覆盖最后一个数组元素值
			strcpy(c[i].name,"");//数组赋值空串
			size--;
			printf("quit->fd=%dquit\n",fd);
			char msg[100] = {};
			sprintf(msg,"欢送 %s 离开本聊天室\n",name);
			//将退出提示发送给所有人
			sendMsgToAll(msg);
			close(fd);//关闭描述符
			return;//客户端退出之后，结束线程
		}
		sendMsgToAll(buf);//如果正确读取到客户端发来的消息，直接将消息分发给所以在线客户即可
	}
}
//2等待客户端连接，启动服务器的服务
void service(){
	printf("服务器开始服务\n");
	while(1){
		struct sockaddr_in fromaddr;//存储客户端的通信地址
		socklen_t len = sizeof(fromaddr);
		int fd = accept(sockfd,(SA*)&fromaddr,&len);
		if(fd == -1){
			printf("客户端连接出错\n");
			continue;//继续下一次循环等待客户端连接
		}
		//有客户端成功连上服务器，记录socket
		c[size].fds = fd;
		printf("fd = %d\n",fd);//测试查看
		//开启线程，为此客户端服务
		pthread_t pid;
		pthread_create(&pid,0,service_thread,&fd);
	}
}
void sig_close(){
	//关闭服务器的socket
	close(sockfd);
	printf("服务器已经关闭..\n");
	exit(0);
}
int main(){
	//对CTRL+C 发的信号进行处理，做好善后工作
	//关闭服务器的socket描述符号
	signal(SIGINT,sig_close);//自定义信号处理函数
	init();//初始化服务器网络
	service();//启动服务
	return 0;
}







