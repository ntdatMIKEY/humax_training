#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Program to read some data from shared memory */
int main() {
	const int SIZE = 4096; /* size of the shared page */
		/* name of the shared page */
	const char * NAME = "MY_PAGE"; 
	int shm_fd;
	char * ptr;
	
	shm_fd = shm_open(NAME, O_RDONLY, 0666);
	ptr = (char *) mmap(0, SIZE, PROT_READ,
		MAP_SHARED, shm_fd, 0);
	printf("%s\n", ptr);
	
	close(shm_fd);
	/*What happen if commment bellow line*/
	//shm_unlink(NAME);
	return 0;
}

