#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(){
  key_t key = ftok(".",100);
  int shmid = shmget(key,0,0);//获取shm
  if(shmid==-1)perror("shmget"),exit(-1);
  struct shmid_ds ds;//查询
  shmctl(shmid,IPC_STAT,&ds);
  printf("size=%d\n",ds.shm_segsz);
  printf("nattch=%d\n",ds.shm_nattch);
  printf("mode=%o\n",ds.shm_perm.mode);
  ds.shm_segsz = 400;//不可修改
  ds.shm_perm.mode = 0644;//可以修改
  shmctl(shmid,IPC_SET,&ds);//修改
  shmctl(shmid,IPC_STAT,&ds);//重新获取
  printf("size=%d\n",ds.shm_segsz);
  printf("mode=%o\n",ds.shm_perm.mode);
  //shmctl(shmid,IPC_RMID,0);//删除
  
}

