#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 10

// Structure for Booking Details
struct Booking
{
    char name[50];
    int row;
    int col;
    int amount;
};

// Function Prototypes
void bookSeat(int **seats, struct Booking *records, int *count);
void cancelBooking(int **seats, struct Booking *records, int *count);
void displaySeats(int **seats);
void displayRecords(struct Booking *records, int count);
int getTicketPrice(int row);

int main()
{
    int i, choice;

    // Dynamic Memory Allocation for 2D Array
    int **seats;

    seats = (int **)malloc(ROWS * sizeof(int *));

    for(i = 0; i < ROWS; i++)
    {
        seats[i] = (int *)calloc(COLS, sizeof(int));
    }

    // Booking records
    struct Booking records[50];
    int bookingCount = 0;

    while(1)
    {
        printf("\n====== THEATRE BOOKING SYSTEM ======\n");
        printf("1. Book Seat\n");
        printf("2. Cancel Booking\n");
        printf("3. Display Seat Status\n");
        printf("4. Display Booking Records\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                bookSeat(seats, records, &bookingCount);
                break;

            case 2:
                cancelBooking(seats, records, &bookingCount);
                break;

            case 3:
                displaySeats(seats);
                break;

            case 4:
                displayRecords(records, bookingCount);
                break;

            case 5:
                printf("Exiting Program...\n");

                // Free dynamically allocated memory
                for(i = 0; i < ROWS; i++)
                {
                    free(seats[i]);
                }

                free(seats);

                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

// Function to get ticket price
int getTicketPrice(int row)
{
    switch(row)
    {
        case 1: return 500;
        case 2: return 400;
        case 3: return 300;
        case 4: return 200;
        case 5: return 100;
        default: return 0;
    }
}

// Function to Book Seat
void bookSeat(int **seats, struct Booking *records, int *count)
{
    int row, col;
    char name[50];

    printf("Enter Customer Name: ");
    scanf("%s", name);

    printf("Enter Row Number (1-5): ");
    scanf("%d", &row);

    printf("Enter Column Number (1-10): ");
    scanf("%d", &col);

    // Validate Input
    if(row < 1 || row > 5 || col < 1 || col > 10)
    {
        printf("Invalid Seat Number!\n");
        return;
    }

    // Check Seat Availability
    if(seats[row-1][col-1] == 1)
    {
        printf("Seat Already Booked!\n");
        return;
    }

    // Book Seat
    seats[row-1][col-1] = 1;

    // Store Booking Record
    strcpy(records[*count].name, name);
    records[*count].row = row;
    records[*count].col = col;
    records[*count].amount = getTicketPrice(row);

    (*count)++;

    printf("\nSeat Booked Successfully\n");
    printf("Ticket Amount = Rs.%d\n", getTicketPrice(row));
}

// Function to Cancel Booking
void cancelBooking(int **seats, struct Booking *records, int *count)
{
    int row, col, i, found = 0;

    printf("Enter Row Number: ");
    scanf("%d", &row);

    printf("Enter Column Number: ");
    scanf("%d", &col);

    // Validate
    if(row < 1 || row > 5 || col < 1 || col > 10)
    {
        printf("Invalid Seat Number!\n");
        return;
    }

    // Check if booked
    if(seats[row-1][col-1] == 0)
    {
        printf("Seat is not booked!\n");
        return;
    }

    // Cancel Seat
    seats[row-1][col-1] = 0;

    // Remove record
    for(i = 0; i < *count; i++)
    {
        if(records[i].row == row && records[i].col == col)
        {
            found = 1;

            // Shift records
            for(int j = i; j < *count - 1; j++)
            {
                records[j] = records[j+1];
            }

            (*count)--;
            break;
        }
    }

    if(found)
    {
        printf("Booking Cancelled Successfully\n");
    }
}

// Function to Display Seat Status
void displaySeats(int **seats)
{
    int i, j;

    printf("\n===== SEAT STATUS =====\n");

    for(i = 0; i < ROWS; i++)
    {
        printf("Row %d : ", i + 1);

        for(j = 0; j < COLS; j++)
        {
            printf("%d ", seats[i][j]);
        }

        printf("\n");
    }
}

// Function to Display All Booking Records
void displayRecords(struct Booking *records, int count)
{
    int i;

    if(count == 0)
    {
        printf("No Bookings Found!\n");
        return;
    }

    printf("\n===== BOOKING RECORDS =====\n");

    for(i = 0; i < count; i++)
    {
        printf("\nCustomer Name : %s\n", records[i].name);
        printf("Seat Number   : Row %d, Column %d\n",
                records[i].row,
                records[i].col);
        printf("Ticket Amount : Rs.%d\n", records[i].amount);
    }
}
