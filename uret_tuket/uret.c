#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main() {
	int pid,ret;
	int pd[2];
		const int SIZE =4096;
		const char *name="OS2";
		
		int shm_fd;
		void *ptr;
	ret=pipe(pd);
	
	if(ret<0){
	printf("Pipe error\n");
	exit(1);
	}	 
	
	pid=fork();
	if(pid>0) //Ebeveyn - yazan
	{	
	  close(pd[0]);//okuma pasif
	  write(pd[1],"Merhaba",8);
	  printf("----Üretici Ebeveyn yazdı-------\n");
	  while(1);
	
	} 
	else if(pid==0)//Yavru -okuyan 
	{
	  char buf[10];
	  close (pd[1]);//yazma pasif
	  read(pd[0],buf,8);//okuma aktif
	  printf("---Üretici Yavru Okudu-------\n");
	  printf("okunan: %s\n",buf);
	  
	  /* create the shared memory segment */
	shm_fd=shm_open(name ,O_CREAT|O_RDWR,0666);
	
	/*configure the size of the shared memory segment */
	ftruncate(shm_fd,SIZE);
	
	/*now map the shared memory segment in the address space of the process*/
	ptr=mmap(0,SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,shm_fd,0);
	if(ptr==MAP_FAILED){
	  printf("map dailed\n");
	  return -1;
	}
	sprintf(ptr,"%s",buf);
	  
	  
	}
	
	
    return 0;
}
