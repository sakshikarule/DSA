#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 5


/* student structure */

struct student
{
	int rollno;
	char name[30];

};

/* stack using Array */

struct student stack[SIZE];
int top = -1;

/*Linked list Node*/

struct node
{
	struct student data;
	struct node *next;
};

struct node *head = NULL;

/*PUSH operation*/

void push()
{

	if (top == SIZE -1)
	{
		printf("\nStack is Full!\n");
		return;
	}

	top++;

	printf("\nEnter roll Number: ");
	scanf("%d", &stack[top].rollno);

	printf("Enter Student Name: ");
	scanf("%s", stack[top].name);

	printf("\nStudent Added into stack!\n");
}

/* POP Operation*/

void pop()
{
	if (top == -1)
	{
		printf("\nStack is Empty!\n");
		return;
	}

	printf("\nDeleted Student; ");
	printf("\nRoll No : %d", stack[top].rollno);
	printf("\nName    : %s\n", stack[top].name);

	top--;
}

/*Display Stack*/
void displayStack()
{
	if (top == -1)
	{
		printf("\nStack is Empty!\n");
		return;
	}

	printf("\n-----Stack Student-----\n");

	for (int i = top; i >=0; i--)
	{
		printf("\nRoll No : %d", stack[i].rollno);
		printf("\nName    : %s", stack[i].name);
	}
}

/*Insert Student at End */

void insertEnd()
{
	struct node *newnode;

	newnode = (struct  node *)malloc(sizeof(struct node));

	printf("\nEnter Roll Number: ");
	scanf("%d", &newnode->data.rollno);

	printf("Enter Student Name: ");
	scanf("%s", newnode->data.name);

	newnode->next = NULL;

	/* If List is Empty */
	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		struct node *temp = head;

		while (temp->next !=NULL)
		{
			temp = temp->next;
		}

		temp->next = newnode;
	}

	printf("\nStudent Inserted Successfully!\n");
}
 
/* Delete First Student */
void deleteBeaginning()
{
	if (head == NULL)
	{
		printf("\nLinked List is Empty!\n");
		return;
	}

	struct node *temp = head;

	printf("\nDeleted Student: ");
	printf("\nRoll No : %d", temp->data.rollno);
	printf("\nName    : %s", temp->data.name);

	head = head->next;

	free(temp);

}

/* Display Linl list */
void displayList()
{
	if (head == NULL)
	{
		printf("\nLinked List is Empty!\n");
		return;
	}

	struct node *temp = head;

	printf("\n----- Linked List Students ------\n");

	while ( temp != NULL)
	{
		printf("\nRoll No : %d", temp->data.rollno);
		printf("\nName    : %s\n",temp->data.name);

		temp = temp->next;
	}
}

/*-----------------------------------------
    Bubble Sort Linked List
-----------------------------------------*/
void bubbleSort()
{
    if (head == NULL)
    {
        printf("\nLinked List is Empty!\n");
        return;
    }

    struct node *i, *j;
    struct student temp;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data.rollno > j->data.rollno)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("\nStudents Sorted by Roll Number!\n");
}

/*-----------------------------------------
    Main Function
-----------------------------------------*/
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n===== STUDENT RECORD MANAGEMENT =====");

        printf("\n1. Push Student");
        printf("\n2. Pop Student");
        printf("\n3. Display Stack");

        printf("\n4. Insert Student at End");
        printf("\n5. Delete First Student");
        printf("\n6. Display Linked List");

        printf("\n7. Bubble Sort Linked List");

        printf("\n8. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            displayStack();
            break;

        case 4:
            insertEnd();
            break;

        case 5:
            deleteBeginning();
            break;

        case 6:
            displayList();
            break;

        case 7:
            bubbleSort();
            break;

        case 8:
            printf("\nProgram Ended!\n");
            exit(0);

        default:
            printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}
