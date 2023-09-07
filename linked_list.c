#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "linked_list.h"

node* create_list(){
	node *val_to_return = malloc(sizeof(node));

	return val_to_return;

}

node* add_node(node *node_to_add_to){
      node_to_add_to->tail = malloc(sizeof(node));

      return node_to_add_to->tail;
}

void generate_list(node *head_node,int size){
	size--;
	if(size == 0)
		return ;

	node *tail = add_node(head_node);
	tail->val = rand() % 200;
	generate_list(tail,size);
}

int len_list(node *head_node){
	int size = 1;
	if (head_node->tail == NULL)
		return size;
	return size + len_list(head_node->tail);
}

void print_list(node *head_node){
	if(head_node->tail !=NULL){
		printf("%d--->", head_node->val);
		print_list(head_node->tail);
	}
	else{
		printf("%d\n", head_node->val);
	}
}

node* reverse_list(node *head_node){

	if (head_node->tail == NULL)
		return head_node;
	node *next_node = reverse_list(head_node->tail);
	head_node->tail->tail = head_node;
	head_node->tail = NULL;
	return next_node;
}



int main(){
	srand(time(NULL));

	node *nascent_node = create_list();

	generate_list(nascent_node,5);
	print_list(nascent_node);
	nascent_node = reverse_list(nascent_node);
	print_list(nascent_node);
	int length = len_list(nascent_node);

	printf("%d\n", length);

	return 0;
}
