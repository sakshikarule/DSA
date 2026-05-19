#include<stdio.h>
#define SIZE 9

int binary_search(int arr[SIZE],int key);
int recursive_binary_Search(int arr[SIZE],int key,int left, int right);
int comparisons;
int main()
{
	int arr[SIZE] = {11,22,33,44,55,66,77,88,99};
	int key;
	printf("Enter the key to search :");
	scanf("%d",&key);
	int index = binary_search(arr,key);
	if(index == -1)
		 printf("key Not found.\n");
	else
		printf("key found at index = %d\n",index);
	    printf("comparisons = %d\n",comparisons);

	printf("\n\n Recursive Binary search : \n");
	index = recursive_binary_serch(arr,key,0,SIZE-1);
	if (index == -1)
		printf("key NOt found.\n");
	else
		printf("key found at index = %d\n",index);

	return 0;
}

int binary_search(int arr[SIZE],int key)
{
	int left = 0, right = SIZE-1, mid;

	while(left <= right)
	{
		mid = (left + right) / 2;
		comparisons++;
		if(key == arr[mid])
		{
			return mid;
		}
		if (key < arr[mid])
		{
			right = mid-1;
		}
		else
		{
			left = mid+1;
		}
    }
return -1;
}

int recursive_binary_search(int arr[SIZE],int key,int left, int right)
{
	if(left > right)
		return -1;


	int mid = (left+right) / 2;
	if(key == arr[mid])
		return mid;
	if (key < arr [mid])
	{
		//continue in left sub array
		recursive_binary_search(arr,key,mid+1,right);
	}
}

