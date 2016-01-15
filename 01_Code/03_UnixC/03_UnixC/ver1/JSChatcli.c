#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
int main(int argc,char* argv[])
{
    if(argc<3)
    {
        printf("用法：%s<ID地址><端口号>\n",argv[0]);
        return -1;
    }
    printf("cli:创建网络套接字\n");
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(-1 == sockfd)
    {
        perror("socket");
        return -1;
    }
    printf("cli:准备地址并连接\n");
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    if(connect(sockfd,(struct sockaddr*)&addr,sizeof(addr)) == -1)
    {
        perror("connect");
        return -1;
    }
    while(1)
    {
        printf("cli:产生数据\n");
        printf(">");
        char buf[1024];
        gets(buf);
        if(!strcmp(buf,"!"))
            break;
        printf("cli:发送请求\n");
        if(send(sockfd,buf,strlen(buf)+1,0) == -1)
        {
            perror("send");
            return -1;
        }
        printf("cli：接受响应\n");
        ssize_t rb = recv(sockfd,buf,sizeof(buf),0);
        if(rb == -1)
        {
            perror("recv");
            return -1;
        }
        if(rb == 0)
        {
            printf("cli：svr已关闭\n");
        }
        printf("<%s\n",buf);
    }
    
    printf("cli：关闭套接字\n");
    close(sockfd);
    return 0;
}
