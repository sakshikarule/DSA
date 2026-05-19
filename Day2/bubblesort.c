#include<stdio.h>
#define SIZE 6

void bubble_sort(int arr[SIZE]);
void display(int arr[SIZE]);
void efficient_bubble_sort(int arr[SIZE]);

int main()
{
	//int arr[SIZE] = {30,20,60,50,10,40};
	int arr[SIZE] = {11,22,33,44,55,66};
	printf("\n Before Normal Sort :\n");
	display(arr);
	bubble_sort(arr);
	printf("\n After Normal Sort :\n");
	display(arr);

	printf("\n Before Efficient Sort :\n");
    display(arr);
	efficient_bubble_sort(arr);
	printf("\n After Efficient Sort :\n");
	display(arr);

	return 0;

}

void bubble_sort(int arr[SIZE])
{
	int iterations = 0, comparisons = 0;

	for(int it = 0; it < SIZE-1; it++) // 5 time : 0 to 4
	{
		iterations++;
		for(int pos = 0; pos < SIZE-1-it; pos++)
		{
			comparisons++;

			if(arr[pos] > arr[pos+1])
			{
				int temp = arr[pos];
				arr[pos] = arr[pos+1];
				arr[pos+1] = temp;
			}
		}
	}
	printf("\nIterations = %d comparisons = %d\n",iterations,comparisons);
}

void display(int arr[SIZE])
{
	for(int i=0; i< SIZE; i++)
	{
		printf("%4d",arr[i]);
	}
}

void efficient_bubble_sort(int arr[SIZE])
{
	int iterations = 0, comparisons = 0;
	int flag;
	for(int it = 0; it < SIZE-1; it++) 
	{
		flag = 0;
		iterations++;
		for(int pos = 0; pos < SIZE-1-it; pos++)
		{
			comparisons++;

			if(arr[pos] > arr[pos+1])
			{
				int temp = arr[pos];
				arr[pos] = arr[pos+1];
				arr[pos+1] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	printf("\nIteration = %d comparsions = %d\n",iterations,comparisons);
}

