#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ENTRIES 10
struct student
{
    int mark , age;
    char name[15];
};
int comparator(const void * a ,const void * b);
int main()
{

    struct student *students = NULL;
    int i =0;

    students = malloc(ENTRIES * sizeof(struct student));
    if(students == NULL)
    {
        printf("Error. \r\n");
        return 0;
    }

    for(i = 0 ; i< ENTRIES ;i++)
    {
        students[i].age = i  + 20;
        students[i].mark = rand() % 500 ;
        memset(students[i].name , 0 , 15);
        sprintf(students[i].name ,"%s%d" , "name" , i);
    }

    for(i = 0 ; i< ENTRIES ;i++)
    {
        printf("Name : %s , Age : %d , Mark : %d \r\n" , students[i].name , students[i].age , students[i].mark); 
    }
    qsort((void *) students , ENTRIES , sizeof(struct student) , comparator);

    printf("------------------------------------------\r\n");
    for(i = 0 ; i< ENTRIES ;i++)
    {
        printf("Name : %s , Age : %d , Mark : %d \r\n" , students[i].name , students[i].age , students[i].mark); 
    }
}


int comparator(const void * a ,const void * b)
{

    int mark1 = ((struct student *)a)->mark;
    int mark2 = ((struct student *)b)->mark;
    
    printf("mark1 : %d  mark2 %d \r\n" , mark1 , mark2);
    return mark1 - mark2;


}
