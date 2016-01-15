#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
  key_t key = ftok(".",100);//当前路径
  if(key == -1) perror("ftok"),exit(-1);
  int shmid=shmget(key,4,IPC_CREAT|0666);
  if(shmid==-1)perror("shmget"),exit(-1);
  void* p = shmat(shmid,0,0);
  if(p == (void*)-1)
    perror("shmat"),exit(-1);
  int* pi = p; *pi = 100;
  //sleep(20);
  shmdt(p);//练习:写shmb.c，把100从共享
}//内存中取出


