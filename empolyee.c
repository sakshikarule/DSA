#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

/*------------------------------------------------
    Structure for Employee Details
------------------------------------------------*/
struct Employee
{
    int id;
    char name[30];
    float salary;
};

/*------------------------------------------------
    Stack Implementation using Array
------------------------------------------------*/
struct Employee stack[MAX];
int top = -1;

/*------------------------------------------------
    Linked List Node
------------------------------------------------*/
struct Node
{
    struct Employee emp;
    struct Node *next;
};

struct Node *head = NULL;

/*------------------------------------------------
    Push Employee into Stack
------------------------------------------------*/
void push()
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow!\n");
        return;
    }

    top++;

    printf("\nEnter Employee ID: ");
    scanf("%d", &stack[top].id);

    printf("Enter Employee Name: ");
    scanf("%s", stack[top].name);

    printf("Enter Employee Salary: ");
    scanf("%f", &stack[top].salary);

    printf("\nEmployee Pushed Successfully!\n");
}

/*------------------------------------------------
    Pop Employee from Stack
------------------------------------------------*/
void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow!\n");
        return;
    }

    printf("\nDeleted Employee:");
    printf("\nID     : %d", stack[top].id);
    printf("\nName   : %s", stack[top].name);
    printf("\nSalary : %.2f\n", stack[top].salary);

    top--;
}

/*------------------------------------------------
    Display Stack
------------------------------------------------*/
void displayStack()
{
    if (top == -1)
    {
        printf("\nStack is Empty!\n");
        return;
    }

    printf("\n===== Employee Stack =====\n");

    for (int i = top; i >= 0; i--)
    {
        printf("\nID     : %d", stack[i].id);
        printf("\nName   : %s", stack[i].name);
        printf("\nSalary : %.2f\n", stack[i].salary);
    }
}

/*------------------------------------------------
    Insert Employee at First
------------------------------------------------*/
void insertFirst()
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter Employee ID: ");
    scanf("%d", &newNode->emp.id);

    printf("Enter Employee Name: ");
    scanf("%s", newNode->emp.name);

    printf("Enter Employee Salary: ");
    scanf("%f", &newNode->emp.salary);

    newNode->next = head;
    head = newNode;

    printf("\nEmployee Inserted at First!\n");
}

/*------------------------------------------------
    Insert Employee at Last
------------------------------------------------*/
void insertLast()
{
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter Employee ID: ");
    scanf("%d", &newNode->emp.id);

    printf("Enter Employee Name: ");
    scanf("%s", newNode->emp.name);

    printf("Enter Employee Salary: ");
    scanf("%f", &newNode->emp.salary);

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("\nEmployee Inserted at Last!\n");
}

/*------------------------------------------------
    Insert Employee at Middle
------------------------------------------------*/
void insertMiddle()
{
    int pos, i;

    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter Position: ");
    scanf("%d", &pos);

    printf("Enter Employee ID: ");
    scanf("%d", &newNode->emp.id);

    printf("Enter Employee Name: ");
    scanf("%s", newNode->emp.name);

    printf("Enter Employee Salary: ");
    scanf("%f", &newNode->emp.salary);

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\nInvalid Position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("\nEmployee Inserted at Middle!\n");
}

/*------------------------------------------------
    Delete First Employee
------------------------------------------------*/
void deleteFirst()
{
    if (head == NULL)
    {
        printf("\nLinked List is Empty!\n");
        return;
    }

    struct Node *temp = head;

    printf("\nDeleted Employee:");
    printf("\nID     : %d", temp->emp.id);
    printf("\nName   : %s", temp->emp.name);
    printf("\nSalary : %.2f\n", temp->emp.salary);

    head = head->next;

    free(temp);
}

/*------------------------------------------------
    Display Linked List
------------------------------------------------*/
void displayList()
{
    if (head == NULL)
    {
        printf("\nLinked List is Empty!\n");
        return;
    }

    struct Node *temp = head;

    printf("\n===== Employee Records =====\n");

    while (temp != NULL)
    {
        printf("\nID     : %d", temp->emp.id);
        printf("\nName   : %s", temp->emp.name);
        printf("\nSalary : %.2f\n", temp->emp.salary);

        temp = temp->next;
    }
}

/*------------------------------------------------
    Bubble Sort by Salary
------------------------------------------------*/
void bubbleSort()
{
    if (head == NULL)
    {
        printf("\nLinked List is Empty!\n");
        return;
    }

    struct Node *i, *j;
    struct Employee temp;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->emp.salary > j->emp.salary)
            {
                temp = i->emp;
                i->emp = j->emp;
                j->emp = temp;
            }
        }
    }

    printf("\nEmployees Sorted by Salary!\n");
}

/*------------------------------------------------
    Main Function
------------------------------------------------*/
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n====== EMPLOYEE MANAGEMENT SYSTEM ======");

        printf("\n1. Push Employee");
        printf("\n2. Pop Employee");
        printf("\n3. Display Employee Stack");

        printf("\n4. Insert Employee at First");
        printf("\n5. Insert Employee at Middle");
        printf("\n6. Insert Employee at Last");

        printf("\n7. Delete First Employee");
        printf("\n8. Display Employee Records");

        printf("\n9. Sort Employees by Salary");

        printf("\n10. Exit");

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
            insertFirst();
            break;

        case 5:
            insertMiddle();
            break;

        case 6:
            insertLast();
            break;

        case 7:
            deleteFirst();
            break;

        case 8:
            displayList();
            break;

        case 9:
            bubbleSort();
            break;

        case 10:
            printf("\nExiting Program...\n");
            exit(0);

        default:
            printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}
