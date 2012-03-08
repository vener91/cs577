#include <stdlib.h>
#include <stdio.h>

struct LinkedList {
	   int val;
	   int first_node;
	   struct LinkedList* next;
};

typedef struct Linkedlist llist;

struct LinkedList* make_llnode(int val){
	struct LinkedList * ll;
	ll = malloc(sizeof(struct LinkedList));
	ll->first_node = 0;
	ll->val = val;
	ll->next = NULL;
	return ll;
}

struct LinkedList* make_linkedlist() {
	struct LinkedList* ll = make_llnode(0);
	ll->first_node = 0;	
	return ll;
}

void ll_insert(struct LinkedList* head, int key){
	struct LinkedList* curr = head;
	struct LinkedList* next;
	while(curr->next != NULL) {
		next = curr->next;
		if(curr->first_node == 1 || (curr->val < key && next->val >= key || next == NULL ) ){	
			curr->next = make_llnode(key);
			curr->next->next = next;
			return;
		}
		curr = curr->next ;
	}
	curr->next = make_llnode(key);
}

int ll_contains(struct LinkedList* head, int key){
	struct LinkedList* curr = head->next;
	while(curr != NULL) {
		if(curr->val == key){
			return 1;
		}
		curr = curr->next ;
	}
	return 0;
}

int ll_delete(struct LinkedList* head, int key){
	struct LinkedList* curr = head->next;
	struct LinkedList* prev = head;

	while(curr != NULL) {
		if(curr->val == key){
			//Delete key
			prev->next = curr->next;
			free(curr);	
			return 1;
		}
		prev = curr ;
		curr = curr->next ;
	}
	return 0;
}

int ll_print(struct LinkedList* head){
	struct LinkedList* curr = head;
	struct LinkedList* next;
	while(curr->next != NULL) {
		printf("%d - ", curr->val);
		curr = curr->next ;
	}
	printf("%d - ", curr->val);
	printf("\n");
}
