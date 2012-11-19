#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define A_MEGABITE (1024 * 1024)

int main(){
	char *some_memory;
	int megabyte = A_MEGABITE;
	int exit_code = EXIT_FAILURE;
	
	some_memory = (char *)malloc(megabyte);
	if (some_memory != NULL){
		sprintf(some_memory,"Hello World");
		printf("%s\n",some_memory);
		exit_code = EXIT_SUCCESS;
	}

	exit(exit_code);
}
