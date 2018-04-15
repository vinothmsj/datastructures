#include <stdlib.h>
#include <stdio.h>


void quicksort(int arr[], int start , int end);
int partition(int arr[], int start , int end);

int partition(int arr[], int start , int end)
{

    int pivot = arr[end];
    int  i =0;
    int temp  =0 ;
    int pindex = start;
    for(i = start ; i < end ; i++)
    {
        if(arr[i] < pivot)
        {
            temp = arr[i];
            arr[i] = arr[pindex];
            arr[pindex] = temp;
            pindex++;
        }
    }
    temp = arr[pindex];
    arr[pindex] = arr[end];
    arr[end] = temp;

    return  pindex;

}
void quicksort(int arr[], int start , int end)
{

    int pindex = 0;
    if(start < end)
    {
        pindex = partition(arr , start , end);
        quicksort(arr , start , pindex-1);
        quicksort(arr , pindex + 1 , end);
    }
}

void main()
{

    int arr[10] = { 20 , 22 , 24, 8 ,10 , 15 , 25 , 60 , 2 , 17};
    int i = 0;
    quicksort( arr , 0 , 9);
    for(i =0 ;i < 10; i++)
    {
        printf("Element : %d \r\n", arr[i]);
    }

}


