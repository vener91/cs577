#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFSIZE (32)

int
main(int argc, char *argv[])
{
	int recordsLeft = 100000;
	int randomSeed = 1;
    // seed random number generator
    srand(randomSeed);

    // open and create output file
    FILE* fd = fopen("./data", "w");
	if (fd < 0) {
		perror("open");
		exit(1);
	}
	int i;
	int action,key;
	for (i = 0; i < recordsLeft; i++) {
		// fill in random key
		action = rand() % 3;
		key = rand()% recordsLeft;
		// fill in random rest of records
		fprintf(fd, "%d:%d\n",action, key);
	}

	// ok to ignore error code here, because we're done anyhow...
	fclose(fd);

	return 0;
}

