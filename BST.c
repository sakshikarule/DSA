#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	int data;
	struct node *right;
};

struct node* root = NULL;
void add_node(int value);

void pre_order(struct node* current);

int main()
{
	add_node(50);
	add_node(25);
	add_node(66);
	add_node(88);
	add_node(20);
	add_node(22);
	add_node(90);
	add_node(50);
	add_node(80);
	add_node(36);

	pre_order(root);
	return 0;

}



struct node * create_node()
{
   struct node *ptr = (struct node*)malloc(sizeof(struct node));
ptr->left = NULL;
ptr->data = 0;
ptr->right = NULL;

   return ptr;
}
 
void add_node(int value)
{
	//create a node
	struct node *new_node = create_node();

	// assign the value to the data field
	new_node->data = value;

	//attch
	//if the tree is empty, attach the node to the root
	if(root == NULL)
	{
		root = new_node;
	}

	else //traverse left or right
	{
		struct node *trav = root;

		while(1)
		{
			if(new_node->data < trav->data)
			{
				//traverse to left
				if(trav->left == NULL)
				{
					trav->left = new_node;
					break;
				}
			}
			else  // data is greater or equal, then go to the left or right
			{
				if(trav->right == NULL)
				{
     				trav->right = new_node;
					break;
				}
			   trav = trav->right;
			}
		}
	}
}

void pre_order(struct node* current)
{
	if(current == NULL)
		return;

	printf("%4d",current->data);
	pre_order(current->left);
	pre_order(current->right);
}


