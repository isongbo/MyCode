
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

/*7 线程主体函数*/
void *pthread_service(void *arg)
{
    /*当客户端断开连接跳出循环*/
    while(1)
    {
        /*8 接收客户端的数据*/

        /*9 将接收到的数据在回传给当前客户端*/
    }
    return NULL;
}


int main()
{
    /*1 创建socket*/
    /*2 准备地址*/
    /*3 绑定*/
    /*4 监听*/

    while(1)
    {
        /*5 accept*/

        /*6 开启新的线程*/
    }

}
