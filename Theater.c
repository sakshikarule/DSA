/* movie theater management system */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 5

/*-------------------------------------------
  Structure for Moive Ticket Record
-------------------------------------------*/
struct Ticket
{
	char customerName[30];
	int  seatNumber;
	char movieName[30];
};

/*-----------------------------------------
  Queue Implementation using Array
-------------------------------------------*/

struct Ticket queue[MAX];
int front = -1, rear = -1;

/*-----------------------------------------
  Linked List Node
------------------------------------------*/
struct Node
{
	struct Ticket data;
	struct Node   *next;
};

struct Node *head = NULL;

/*----------------------------------------
  Function to Add Ticket into Queue
----------------------------------------*/
void addToQueue()
{

	if (rear == MAX - 1)
	{
		printf("\nQueue is Full!\n");
		return;
	}
	 
	struct Ticket t;

	printf("\nEnter Customer Name: ");
	scanf("%s", t.customerName);

	printf("Enter Seat Number: ");
	scanf("%d", &t.seatNumber) ;

	printf("Enter the Moive Name: ");
	scanf("%s", t.movieName);

	if (front == -1)
		front = 0;


	rear++;
	queue[rear] = t;

	printf("\nTicket Added to Waiting Queue Successfully!\n");
}

/*-----------------------------------------------------
  Function to Remove Ticket from Queue
  ------------------------------------------------*/
void removeFromQueue()
{
	if (front == -1 || front > rear)
	{
		printf("\nQueue is Empty!\n");
		return;
	}

	printf("\nRemoved customer: %s",
		   queue[front].customerName);

	front++;
    
	if (front > rear)
	{
		front = rear = -1;
	}
}

/*--------------------------------------------------
  Function to Display Queue
  -------------------------------------------------*/
void displayQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty!\n");
		return;
	}

	printf("\n------Waiting Queue --------\n");

	for (int i = front; i <= rear; i++)
	{
		printf("\nCustomer Name : %s", queue[i].customerName);
		printf("\nSeat Number   : %d", queue[i].seatNumber);
	    printf("\nMovie Name    : %s\n", queue[i].movieName);
	}
}

/*---------------------------------------------------------
  Function to Insert Ticket into Linked list
  ---------------------------------------------------------*/
void bookTicket()
{
	struct Node *newNode;
	
	newNode = (struct Node*)malloc(sizeof(struct Node));

	printf("\nEnter Customer Name: ");
	scanf("%s", newNode->data.customerName);

	printf("Enter seat Nnmber:  ");
	scanf("%d", &newNode->data.seatNumber);

	printf("Enter Moive Name: ");
	scanf("%s", newNode->data.movieName);

	newNode->next = NULL;

	/* IF list is empty */
	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		struct Node *temp = head;

		while (temp->next !=NULL)
		{
			temp = temp->next;
		}

		temp->next = newNode;
	}

	printf("\nMoive Ticket Booked successfully!\n");
}

/*----------------------------------------------------------
  Function to Delete First  Ticket
  ----------------------------------------------------------*/
void cancelFirstTicket()
{
	if (head == NULL)
	{
		printf("\nNO Ticket Booked!\n");
		return;
	}

	struct Node *temp = head;

	printf("\nCanceled Ticked of %s\n",
			temp->data.customerName);

	head = head->next;

	free(temp);
}

/*-----------------------------------------------------------

  Function to display linked list
  -------------------------------------------------------------*/
void displayBookTickets()
{
	if (head == NULL)
	{
	     printf("\nNo Ticket Booked!\n");
		 return;
	}

	struct Node *temp = head;

	printf("\n-------Booked Ticket ---------\n");
	
	while (temp != NULL)
	{
		printf("\nCustomer Name : %s",
				temp->data.customerName);

		printf("\nSeat Number   : %d",
				temp->data.seatNumber);

		  printf("\nMovie Name    : %s\n",
               temp->data.movieName);


		temp = temp->next;
	}
}

/*-------------------------------------------------------------
  Function to sort Ticket by seat number
  -------------------------------------------------------------*/
void sortTicket()
{
	if (head == NULL)
	{
		printf("\nNO Ticket to Sort!\n");
		return;
	}

	struct Node *i, *j;
	 struct Ticket temp;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data.seatNumber > j->data.seatNumber)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("\nTickets Sorted by Seat Number!\n");
}

/*-------------------------------------------------
    Main Function
-------------------------------------------------*/
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n===== MOVIE THEATER MANAGEMENT SYSTEM =====");

        printf("\n1. Add Customer to Queue");
        printf("\n2. Remove Customer from Queue");
        printf("\n3. Display Waiting Queue");

        printf("\n4. Book Movie Ticket");
        printf("\n5. Cancel First Ticket");
        printf("\n6. Display Booked Tickets");

        printf("\n7. Sort Tickets by Seat Number");

        printf("\n8. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addToQueue();
            break;

        case 2:
            removeFromQueue();
            break;

        case 3:
            displayQueue();
            break;

        case 4:
            bookTicket();
            break;

        case 5:
            cancelFirstTicket();
            break;

        case 6:
            displayBookTickets();
            break;

        case 7:
            sortTicket();
            break;

        case 8:
            printf("\nExiting Program...\n");
            exit(0);

        default:
            printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}
