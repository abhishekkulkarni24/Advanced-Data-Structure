#include<stdio.h>
#include<stdlib.h>

/* XOR List Program */

typedef struct node{
	int data;
	struct node *npx;
}node1;


node1 *head=NULL;
node1 *tail=NULL;

node1* XOR(node1 *a,node1 *b){
	return (node1*) (( unsigned int) (a) ^ (unsigned int) (b));
}

void create(){
	
	node1 *temp;
	temp = (node1*) malloc (sizeof(node1*));
	printf("\nEnter Data");
	scanf("%d",&temp->data);
	temp->npx = XOR(tail,NULL);
	
	
	if(head == NULL){
		head = temp;
	}
	
	if(tail != NULL){
		node1 *next = XOR(tail->npx,NULL);
		tail->npx = XOR(temp,next);
		tail = temp;
	}
	
}

void print(){
	node1 *curr = head;
	node1 *prev = NULL;
	node1 *next;
	
	printf("Following Nodes are\n");
	
	while(curr!=NULL){
		printf("%d\t",curr->data);
		next = XOR(prev,curr->npx);
		prev=curr;
		curr=next;
	}
}

int main() {
	
	create();
	
	print();
	
	return 0;
}


/*

Output


Enter Data12
Following Nodes are
12

*/