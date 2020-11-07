//Searching
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int arr[6];
void linearSearch(int arr[],int val)
{
    for (int i = 0; i < 6; i++)
    {
        if (arr[i]==val)
        {
            printf("\nYes, %d is present in the Array at postion %d",val,i);
            return;
        }
    }
    printf("\nNo, %d is not present in the array",val);
}
void BinarySearch(int arr[],int val)
{
    int beg=0,end=6,mid;
    while(beg<=end){
        mid=(beg+end)/2;
        if (arr[mid]==val)
        {
            printf("\nYes, %d is present in the Array at postion %d",val,mid);
            return;
        }
        else if (arr[mid]>val)
        {
            end=mid-1;
        }
        else
            beg=mid+1;
    }  
     printf("\nNo, %d is not present in the array",val);
}
int main()
{
    int val;
    printf("\nEnter six numbers for Linear Search: ");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the value to be searched : ");
    scanf("%d",&val);
    linearSearch(arr, val);
    printf("\nEnter six numbers for Binary Search(Ascending Order): ");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the value to be searched : ");
    scanf("%d",&val);
    BinarySearch(arr, val);
    return 0;
}