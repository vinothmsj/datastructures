#include <stdio.h>

int arry[5] = {10 , 20 , 25 , 30 , 35};

void main()
{

    int start = 0;
    int end = sizeof(arry)/sizeof(arry[0]) - 1;
    int mid =0;
    int element = 0;
    int flag = 0;
    while(start <= end)
    {
        mid = (start+ end) /2;
        if( element == arry[mid])
        {
            flag =1;
            break;
        }
        else if(element > arry[mid])
        {
            start = mid + 1;
        }
        else if(element < arry[mid])
        {
            end = mid -1;
        }
    }
    flag == 1? printf("element found\r\n"):printf("Element not found \r\n");
}

