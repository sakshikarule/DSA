#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;


node* head = NULL;

node* create_node();
void add_node_at_first_pos(int value);
void display();
void add_node_at_last_pos(int value);
void delete_first_node();
void delete_last_node();

int main()
{
	add_node_at_first_pos(10);
	add_node_at_first_pos(15);
	add_node_at_first_pos(20);
	printf("\nAdd Node at first pos :\n");
    display();
	// Head->20->15->10

	add_node_at_last_pos(45);
	add_node_at_last_pos(25);
	add_node_at_last_pos(35);
	printf("\n\nAdd Node at Last pos :\n");
	display();
	// Head->20->15->10->45->25->35

	
	delete_first_node();
	printf("\n\nDelete First Node :\n");
	display();
	//Head->15->10->45->25->35


	delete_last_node();
	printf("\n\nDelete Last Node :\n");
	display();
	// Head->15->10->45->25



    return 0;
}


node* create_node()
{
	node* ptr = (node*)malloc(sizeof(node));

	if(ptr == NULL)
	{
		printf("Malloc Failed.\n");
	}
	else
	{
	ptr->data = 0;
	ptr->next = NULL;
	}
	return ptr;
}

void add_node_at_first_pos(int value)
{
	node *new_node = create_node();
	new_node->data = value;

	if(head == NULL)
	{
		head = new_node;
		new_node->next = head; //circular
	}
	else
	{
		struct node *trav = head;

		while(trav->next != head)
		{
			trav = trav->next;
		}
		new_node->next = head;
		head = new_node;
		trav->next = head; //circular
	}
}
void display()
{
	struct node *trav = head;

	printf("Head");
	do
	{
		printf("->%d",trav->data);
		trav = trav->next;
	} while (trav != head);
}


void add_node_at_last_pos(int value)
{
	node* new_node = create_node();
	new_node->data = value;

	if(head == NULL)
	{
		head = new_node;
		new_node->next = head;
	}
	else
	{
		struct node *trav = head;

		while(trav->next != head)
			trav = trav->next;
		
		trav->next = new_node;
		new_node->next = head; //circular
    }
}

void delete_first_node()
{
	if(head->next == head)
	{
		free(head);
		head = NULL;
	}
	else
	{
		node *trav = head;
		while(trav->next != head)
			 trav = trav->next;

		node* temp = head;
		head = temp->next;

		trav->next = head;
		free(temp);
		temp = NULL;
	}
}

void delete_last_node()
{
	if(head->next == head)
	{
		free(head);
		head = NULL;
	}
	else
	{
		node* trav = head;

		while(trav->next->next != head);
		   trav = trav->next;

		free(trav->next);
		trav->next = head;
	}
}
