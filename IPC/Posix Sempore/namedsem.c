# include	<semaphore.h>	
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char **argv)
{
	int c, flags;
	sem_t *sem;
	unsigned int value;

	flags = O_RDWR | O_CREAT;
	value = 1;

sem = sem_open("/tmp/sem1", flags, (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH), value);
//int a=sem_init(sem,0,1);
if(sem==SEM_FAILED)
printf("sem=%d\n",sem);
else
printf("okk!!\n");
sleep(100);
	sem_close(sem);
	exit(0);
}
