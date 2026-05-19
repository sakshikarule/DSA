#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *head = NULL;


void add_node_at_first_pos(int value);
void display();
void add_node_at_last_pos(int value);
void add_node_at_specific_pos(int value,int pos);
int count_nodes();
void delete_first_node();
void delete_last_node();
void delete_specific_node(int pos);

int main()
{
	add_node_at_first_pos(10);
	add_node_at_first_pos(20);
	add_node_at_first_pos(5);
	add_node_at_first_pos(15);

	//head->15->5->20->10
	printf("Add node at first pos :\n");
	display();

	add_node_at_last_pos(45);
	add_node_at_last_pos(25);
	add_node_at_last_pos(50);
	//head->15->5->20->10->45->25->50
	printf("\n\nAdd node at Last pos :\n");
	display();

	add_node_at_specific_pos(75,5);
	printf("\n\nAdd node at 5th pos :\n");
    //head->15->5->20->10->75->45->25->25->50
	display();

	delete_first_node();
	printf("\n\n Delete First node :\n");
	//head->5->20->10->75->45->25->50
	display();

	delete_last_node();
	printf("\n\n Delete Last node ;\n");
	//head->5->20->10-75->45->25
	display();

	delete_specific_node(4);
	printf("\n\n Delete 4th node :\n");
	//head->5->20->10->45->25
	display();
	return 0;

}

struct node* create_node()
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	// we will assign some default values to the fields of the node created
	     ptr->data = 0;
         ptr->next = NULL;
		 return ptr; //return 500
}

//add_node_at_first_pos (10)
void add_node_at_first_pos(int value)
{
	//create a node.
	struct node *ptr = create_node();

	//assign the value to the data field
	ptr->data = value; //10

	//attach the node to the linked list
	//a. if the list is empty

	if(head == NULL)
	{
		head = ptr;
	}
	else //if the list has multiple nodes
	{
		//1. attach the new node to the first node of the list
            ptr ->next = head;

		//2. update the head pointer to point to the new node
			head = ptr;
	}
}


void display()
{
	if(head == NULL)
		printf("List is empty.\n");
	else
	{
		struct node *trav = head;
		
		//traverse the pointer beyond the last node

		printf("Head");
		while(trav != NULL)
		{
			printf("->%d",trav->data);
			trav = trav->next;
		}
	}
}


void add_node_at_last_pos(int value)
{
	//create a node
	struct node *ptr = create_node();

	//assign the value to the data field
	ptr->data = value;

	//attach the node to the list
	 //a. if the list is empty.
	if(head == NULL)
		head = ptr;
	else
	{
		//take a trav pointer and traverse till  the last node
		   struct node *trav = head;

		   while(trav->next != NULL);
		        trav = trav->next;

		   //attach the new node to the last node
		   trav->next = ptr;
	}
}

void add_node_at_specific_pos(int value,int pos)
{
	if(head == NULL)
	{
		if(pos == 1)
			add_node_at_first_pos(value);
		else
			printf("Cannot add at this pos.\n");
	}
	else if(pos == 1)
		add_node_at_first_pos(value);
	else if(pos == count_nodes()+1)
		add_node_at_last_pos(value);
	else if(pos < 1 || pos > count_nodes()+1)
		printf("Cannot add node at this pos.\n");
	else
	{
		struct node *ptr = create_node();
		ptr->data = value;

		struct node *trav = head;
		for(int i = 1; i<pos-1; i++)
			trav = trav->next;

		ptr->next = trav->next;
		trav->next = ptr;
	}

}

int count_nodes()
{
	struct node *trav = head;
	int count = 0;


	while(trav != NULL)
	{
		count++;
		trav = trav->next;
	}
	return count;
}

void delete_first_node()
{
	if(head == NULL)
		printf("List is empty.\n");
	else if(head->next == NULL)
	{
        free(head);
		head = NULL;
	}
	else
	{
		struct node *temp = head;
		head = head->next;
		//OR head = temp->next;
          
		free(temp);
		temp = NULL;
	}
}

void delete_last_node()
{
	if(head == NULL)
		printf("List is empty.\n");
	else if(head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		struct node *trav = head;

		//travese till second last node
		while(trav->next->next != NULL)
			trav = trav->next;

		//free the last node using trav.
		free(trav->next);
		trav->next = NULL;
	}
}

void delete_specific_node(int pos)
{
	if(head == NULL)
	{
		printf("List is empty.\n");
	}
	else if(pos == 1)
		delete_first_node();
	else if(pos == count_nodes())
		delete_last_node();
	else if(pos < 1 || pos > count_nodes())
		printf("Cannot delate the node at this pos.\n");
	else
	{
		struct node *trav = head;

		for(int i =1; i<pos-1; i++)
			trav = trav->next;

		struct node *temp = trav->next;

		//connect the pos -1 node and pos+1 node.
		trav->next = temp->next;

		free(temp);
		temp = NULL;
	}
}





