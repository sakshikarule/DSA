#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

/*------------------------------------------------
    Structure for Bank Account
------------------------------------------------*/
struct Account
{
    int accNo;
    char name[30];
    float balance;
};

/*------------------------------------------------
    Queue using Array
------------------------------------------------*/
struct Account queue[MAX];

int front = -1;
int rear = -1;

/*------------------------------------------------
    Linked List Node
------------------------------------------------*/
struct Node
{
    struct Account acc;
    struct Node *next;
};

struct Node *head = NULL;

/*------------------------------------------------
    Add Customer to Queue
------------------------------------------------*/
void enqueue()
{
    if (rear == MAX - 1)
    {
        printf("\nQueue Overflow!\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;

    printf("\nEnter Account Number: ");
    scanf("%d", &queue[rear].accNo);

    printf("Enter Customer Name: ");
    scanf("%s", queue[rear].name);

    printf("Enter Balance: ");
    scanf("%f", &queue[rear].balance);

    printf("\nCustomer Added to Queue!\n");
}

/*------------------------------------------------
    Remove Customer from Queue
------------------------------------------------*/
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow!\n");
        return;
    }

    printf("\nRemoved Customer:");
    printf("\nAccount No : %d", queue[front].accNo);
    printf("\nName       : %s", queue[front].name);
    printf("\nBalance    : %.2f\n", queue[front].balance);

    front++;

    if (front > rear)
    {
        front = rear = -1;
    }
}

/*------------------------------------------------
    Display Queue
------------------------------------------------*/
void displayQueue()
{
    int i;

    if (front == -1)
    {
        printf("\nQueue is Empty!\n");
        return;
    }

    printf("\n===== Customer Queue =====\n");

    for (i = front; i <= rear; i++)
    {
        printf("\nAccount No : %d", queue[i].accNo);
        printf("\nName       : %s", queue[i].name);
        printf("\nBalance    : %.2f\n", queue[i].balance);
    }
}

/*------------------------------------------------
    Insert Account at First
------------------------------------------------*/
void insertFirst()
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter Account Number: ");
    scanf("%d", &newNode->acc.accNo);

    printf("Enter Customer Name: ");
    scanf("%s", newNode->acc.name);

    printf("Enter Balance: ");
    scanf("%f", &newNode->acc.balance);

    newNode->next = head;
    head = newNode;

    printf("\nAccount Inserted Successfully!\n");
}

/*------------------------------------------------
    Delete First Account
------------------------------------------------*/
void deleteFirst()
{
    if (head == NULL)
    {
        printf("\nLinked List is Empty!\n");
        return;
    }

    struct Node *temp;

    temp = head;

    printf("\nDeleted Account:");
    printf("\nAccount No : %d", temp->acc.accNo);
    printf("\nName       : %s", temp->acc.name);
    printf("\nBalance    : %.2f\n", temp->acc.balance);

    head = head->next;

    free(temp);
}

/*------------------------------------------------
    Display All Accounts
------------------------------------------------*/
void displayList()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("\nLinked List is Empty!\n");
        return;
    }

    temp = head;

    printf("\n===== Account Records =====\n");

    while (temp != NULL)
    {
        printf("\nAccount No : %d", temp->acc.accNo);
        printf("\nName       : %s", temp->acc.name);
        printf("\nBalance    : %.2f\n", temp->acc.balance);

        temp = temp->next;
    }
}

/*------------------------------------------------
    Bubble Sort by Balance
------------------------------------------------*/
void bubbleSort()
{
    struct Node *i, *j;
    struct Account temp;

    if (head == NULL)
    {
        printf("\nLinked List is Empty!\n");
        return;
    }

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->acc.balance > j->acc.balance)
            {
                temp = i->acc;
                i->acc = j->acc;
                j->acc = temp;
            }
        }
    }

    printf("\nAccounts Sorted by Balance!\n");
}

/*------------------------------------------------
    Main Function
------------------------------------------------*/
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n====== BANK ACCOUNT MANAGEMENT SYSTEM ======");

        printf("\n1. Add Customer to Queue");
        printf("\n2. Remove Customer from Queue");
        printf("\n3. Display Customer Queue");

        printf("\n4. Insert Account at First");
        printf("\n5. Delete First Account");
        printf("\n6. Display All Accounts");

        printf("\n7. Sort Accounts by Balance");

        printf("\n8. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            displayQueue();
            break;

        case 4:
            insertFirst();
            break;

        case 5:
            deleteFirst();
            break;

        case 6:
            displayList();
            break;

        case 7:
            bubbleSort();
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
