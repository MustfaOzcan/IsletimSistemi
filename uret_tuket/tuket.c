#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>


int main() {
	
	const char *name="OS2";
	const int SIZE=4096;
	int shm_fd,pid,pd[2];
	void *ptr;
	int i;
	pid =fork();
	
	if(pid==0)//cocuk okuyan 
	{	
	 
	 close(pd[1]);//yazma pasif
	 /*open the shared memory segment*/
	 shm_fd=shm_open(name,O_RDONLY,0666);
	 if(shm_fd==-1)
	 {
	  printf("shared memory failed\n");	
	  exit(-1);
	 }	
	 /*now map the shared memory segment in the adress space of the process*/
	 ptr=mmap(0,SIZE,PROT_READ,MAP_SHARED,shm_fd,0);
	 if(ptr==MAP_FAILED)
	 {
	  printf("Map failed\n");
	  exit(-1);
	 }
	 printf("Adres2:%p\n", (void*)ptr);
	 
	 /*now read from the sharesd memory region*/
	 printf("%s",(char*)ptr);
	 /*remove the shared memory segment */
	 if(shm_unlink(name)==-1){
	 	printf("error removing %s\n",name );
	 	exit(-1);
	 }
	 
	 write(pd[1],(char*)ptr,8);
	 printf("--------çocuk yazdı---------\n");
 }
 
	 else if(pid>0)//evebeyn okuyan
	 {
	 	
	 	char buf[10];
	 	close(pd[1]);//yazma pasif
	 	read(pd[0],buf,8);//okuma aktif
	 	printf("---Evebeyn okudu-----");
	 	printf("okunan=%s",buf);
	 	while(1);
	 }

	}

    

