#include <stdio.h>

typedef struct Node{

	struct Node *head;
	struct Node *tail;
	int val;

} node;


node* create_list();
void delete_list( node *to_delete);
node* add_node(node *node_to_add_to);
node* remove_node(node *to_remove);
