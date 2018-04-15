#include <stdio.h>

int arry[5] = {10 , 20 , 25 , 30 , 35};

int binary_recur(int start ,int end);
int flag = 0;
int element = 0;
void main()
{

    int start = 0;
    int end = sizeof(arry)/sizeof(arry[0]) - 1;
    binary_recur(start , end);
    flag == 1? printf("element found\r\n"):printf("Element not found \r\n");
}

int binary_recur(int start ,int end )
{
    int mid =0;
    if(start <= end)
    {
        return flag;
    }
    mid = (start+ end) /2;
    if( element == arry[mid])
    {
        flag =1;
        return flag;
    }
    else if(element > arry[mid])
    {
        start = mid + 1;
        binary_recur(start , end);
    }
    else if(element < arry[mid])
    {
        end = mid -1;
        binary_recur(start , end);
    }
    return flag;
}
