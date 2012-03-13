#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


#include "skip_list.c"
#include "linked_list.c"
#include "array_list.c"
int main(int argc, char *argv[]){
	// arguments
	char *inFile = NULL;
	int implementation = -1;
	// input params
	int c;
	opterr = 0;
	while ((c = getopt(argc, argv, "d:i:")) != -1) {
		switch (c) {
			case 'd':
				inFile = strdup(optarg);
				break;
			case 'i':
				implementation = atoi(strdup(optarg));
				break;
			default:
				printf("Invalid argument\n");
				exit(1);
		}
	}

	//Check for required arguments
	if(inFile == NULL || implementation == -1){
		printf("Missing input file or implementation\n");
		exit(1);
	}

	FILE* target_stream;
	//Read in a file
	target_stream = fopen(inFile, "r");
	if (target_stream == NULL) {
		printf("Error opening stream\n");
		exit(1);
	}

	SkipSet* ss = NULL;
	struct LinkedList* ll = NULL;
	ArrayList list;
	//Does some initialization for implementations
	switch(implementation){
		case 0: //Skiplist
    		ss = make_skipset();
			break;
		case 1: //
			ll = make_linkedlist();
			break;
		case 2:
			init(&list);
			break;
		default:
			printf("Implementation not supported\n");
			exit(1);
	}
/*
	//BEGIN OF TEST
	add(&list, (Element){1});
	add(&list, (Element){1});
	add(&list, (Element){3});
	add(&list, (Element){4});
	print(&list);
	//END OF TEST
*/
	//Read file
	const int MAX_LINE = 1024;
	char in[MAX_LINE];

	srand(10);
	while(1){ //Infinity loop
		if(fgets(in, MAX_LINE, target_stream) == NULL){
			if(feof(target_stream)){
				//Read till the end of file for batch mode
				break;
			}else{
				printf("Error reading file\n");
				exit(1);
			}
		}

		strtok(in, "\n"); //Trick to remove new lines
		int key = atoi(in);
		int action = rand() % 3;
		//printf("%d\n", action);
		//printf("%d:%d:%d\n",implementation, action, key);
		switch(implementation){
			case 0: //Skiplist
				switch(action){
					case 0:
						ss_insert(ss, key);
						//do typical number of skipped nodes
						
						break;
					case 1:
						ss_contains(ss, key);
						break;
					case 2:
    					if(ss_contains(ss, key)){
							ss_delete(ss, key);
						}
						break;
				}
				break;
			case 1: //Linked list
				switch(action){
					case 0:
						ll_insert(ll, key);
						//ll_print(ll);
						break;
					case 1:
						ll_contains(ll, key);
						break;
					case 2:
    					ll_delete(ll, key);
						break;
				}
				break;
			case 2: //Array
				switch(action){
					case 0:
						;
						Element* e = malloc(sizeof(Element));
						e->data = key;
						add(&list, *e);
						break;
					case 1:
						;
						Element* e2 = malloc(sizeof(Element));
						e2->data = key;
						indexOf(&list, *e2);
						break;
					case 2:
						;
						Element* e3 = malloc(sizeof(Element));
						e3->data = key;
						int res = indexOf(&list, *e3);
						if(res > 0){
							Element x = list.elements[res];
							//printf("%d\n", x.data);
							//removeAt(&list, res);
						}
						break;
				}
				break;
		}
	}
	return 0;
}
