#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROWS 5
#define COLS 10

// Structure for booking details
struct Booking
{
    char name[50];
    int row;
    int col;
    int amount;
};

int main()
{
    int i, j, choice;
    int row, col;
    int count = 0;

    // Dynamic Memory Allocation for 2D Array
    int **seat;

    seat = (int **)malloc(ROWS * sizeof(int *));

    for(i = 0; i < ROWS; i++)
    {
        // calloc initializes all seats with 0
        seat[i] = (int *)calloc(COLS, sizeof(int));
    }

    // Array for storing booking records
    struct Booking b[50];

    while(1)
    {
        printf("\n====== THEATRE BOOKING SYSTEM ======\n");

        printf("1. Book Seat\n");
        printf("2. Cancel Booking\n");
        printf("3. Display Seat Status\n");
        printf("4. Display Booking Records\n");
        printf("5. Exit\n");

        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {

            // ================= BOOK SEAT =================
            case 1:

                printf("Enter Customer Name : ");
                scanf("%s", b[count].name);

                printf("Enter Row Number (1-5) : ");
                scanf("%d", &row);

                printf("Enter Column Number (1-10) : ");
                scanf("%d", &col);

                // Check valid seat
                if(row < 1 || row > 5 || col < 1 || col > 10)
                {
                    printf("Invalid Seat Number\n");
                    break;
                }

                // Check seat already booked
                if(seat[row-1][col-1] == 1)
                {
                    printf("Seat Already Booked\n");
                    break;
                }

                // Book seat
                seat[row-1][col-1] = 1;

                // Store booking details
                b[count].row = row;
                b[count].col = col;

                // Ticket price according to row
                if(row == 1)
                    b[count].amount = 500;

                else if(row == 2)
                    b[count].amount = 400;

                else if(row == 3)
                    b[count].amount = 300;

                else if(row == 4)
                    b[count].amount = 200;

                else
                    b[count].amount = 100;

                count++;

                printf("Seat Booked Successfully\n");
                printf("Ticket Amount = Rs.%d\n",
                        b[count-1].amount);

                break;

            // ================= CANCEL BOOKING =================
            case 2:

                printf("Enter Row Number : ");
                scanf("%d", &row);

                printf("Enter Column Number : ");
                scanf("%d", &col);

                // Check valid seat
                if(row < 1 || row > 5 || col < 1 || col > 10)
                {
                    printf("Invalid Seat Number\n");
                    break;
                }

                // Check seat booked or not
                if(seat[row-1][col-1] == 0)
                {
                    printf("Seat is Empty\n");
                    break;
                }

                // Cancel seat
                seat[row-1][col-1] = 0;

                // Remove record
                for(i = 0; i < count; i++)
                {
                    if(b[i].row == row &&
                       b[i].col == col)
                    {
                        // Shift records left
                        for(j = i; j < count-1; j++)
                        {
                            b[j] = b[j+1];
                        }

                        count--;
                        break;
                    }
                }

                printf("Booking Cancelled Successfully\n");

                break;

            // ================= DISPLAY SEATS =================
            case 3:

                printf("\n===== SEAT STATUS =====\n");

                for(i = 0; i < ROWS; i++)
                {
                    printf("Row %d : ", i+1);

                    for(j = 0; j < COLS; j++)
                    {
                        printf("%d ", seat[i][j]);
                    }

                    printf("\n");
                }

                break;

            // ================= DISPLAY RECORDS =================
            case 4:

                if(count == 0)
                {
                    printf("No Booking Records Found\n");
                }
                else
                {
                    printf("\n===== BOOKING RECORDS =====\n");

                    for(i = 0; i < count; i++)
                    {
                        printf("\nCustomer Name : %s\n",
                               b[i].name);

                        printf("Seat Number   : Row %d Column %d\n",
                               b[i].row,
                               b[i].col);

                        printf("Ticket Amount : Rs.%d\n",
                               b[i].amount);
                    }
                }

                break;

            // ================= EXIT =================
            case 5:

                // Free dynamically allocated memory
                for(i = 0; i < ROWS; i++)
                {
                    free(seat[i]);
                }

                free(seat);

                printf("Program Ended...\n");

                exit(0);

            default:

                printf("Invalid Choice\n");
        }
    }

    return 0;
}
