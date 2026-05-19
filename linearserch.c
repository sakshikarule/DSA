#include<stdio.h>
#define SIZE 9
int linear_search(int arr[SIZE],int key);
int comparisons;
int main()
{
    int arr[SIZE] = {33,55,88,77,44,11,66,22,99};
    int key;
    // 1. get the key from the user
    printf("Enter the key to search :");
    scanf("%d",&key);
    int index = linear_search(arr,key);
    if(index == -1)
        printf("Key Not Found !\n");
    else
        printf("Key found at index %d\n",index);
        printf("No. of comparisons = %d\n",comparisons);

    return 0;
}

int linear_search(int arr[SIZE],int key)
{
    // 2. Start the traversal

    for(int i =0; i<SIZE; i++)
    {
        comparisons++;
        // 3. compare the key with each element
        if(key == arr[i])
        {
            return i;  // return index
        }
    }
    return -1;// return false
}


