#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>


/* Program to write some data in shared memory */
int main() {
	const int SIZE = 4096; /* size of the shared page */
		/* name of the shared page */
	const char * NAME = "MY_PAGE"; 
	const char * msg = "Hello World!";
	int shm_fd;
	char * ptr;
	
	shm_fd = shm_open(NAME, O_CREAT | O_RDWR, 0666);
	ftruncate(shm_fd, SIZE);
	ptr = (char *) mmap(0, SIZE, PROT_WRITE,
		MAP_SHARED, shm_fd, 0);
	sprintf(ptr, "%s", msg);
	close(shm_fd);

	/*What happen if not commment bellow line*/
	//shm_unlink(NAME);
	return 0;
}

