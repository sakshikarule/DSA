#include<stdio.h>
#include<stdlib.h>



struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

struct node* head = NULL;
struct node* tail = NULL;



struct nose* create_node();

void add_node_at_frist_pos(int value);
void backward_traveral();
void forward_traveral();
void add_node_at_last_pos(int value);
void add_node_at_specific_pos(int value, int pos);
int count_nodes();
void delete_first_nodes();
void delete_last_node();
void delete_specific_node(int pos);

int main()
{
	add_node_at_first_pos(10);
	add_node_at_first_pos(15);
	add_node_at_first_pos(35);
	add_node_at_first_pos(25);

	printf("Forward Traversal :\n");
	forward_traveral();
	//head ->25->30->15->10

	printf("\n\nBackward Traversal :\n");
	backward_traversal();
	//tail->10->15->30->25

	add_node_at_last_pos(45);
	add_node_at_last_pos(70);
	add_node_at_last_pos(11);
	printf("\n\nForward Traversal :\n");
	forward_traversal();
	//head->25->30->15->10->45->70->11

	add_node_at_specific_pos(50,5);
	printf("\n\nAdd Node at 5th position :\n");
	forward_traversal();
	// head->25->30->15->10->50->45->70->11

	delete_first_node();
	printf("\n\nDelete First node :\n");
	forward_traversal();
	// head->30->15->10->50->45->70->11

	
	delete_last_node()
	printf("\n\nDelete Last node :\n");
	forward_traversal();
	//head->30->15->10->50->45->70


	delete_specific_node()
	printf("\n\nDelete 4th node :\n");
	forward_traversal();
	//head->30->15->10->45->70


	return 0;
}

struct node* create_node()
{
	struct node* ptr = (struct node*)malloc(sizeof(struct node));

	if(ptr == NULL)
		printf("Malloc Failed.\n")
	else
	{
		ptr->prev = NULL;
		ptr->data = 0;
		ptr->next = NULL;
	}
    return ptr;
}

void add_node_at_first_pos(int value)
{
	struct node* new_data = create_node();
	new_node->data = value;

	if(head == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
}

void forward_traversal()
{
	struct node* trav = head;

	printf("Head");
	while(trav != NULL)
	{
		printf("->%d",trav->data);
		trav = trav->next;
	}
}


void backward_traversal()
{
	struct node* trav = tail;

	printf("tail");
	while(trav != NULL)
	{
		printf("->%d",trav->data);
		trav-> trav->prev;
    }
}
void add_node_at_last_pos(int value)
{
	struct node* new_node = create_node();
    new_node->data = value;

	if(head == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
	}
}

void add_node_at_specific_pos(int value, int pos)
{
	if(head == NULL)
	{
		if (pos == 1)
			  add_node_at_first_pos(value);
		else
			printf("Cannot add the node at this pos.\n");
	}
	else if (pos == 1)
