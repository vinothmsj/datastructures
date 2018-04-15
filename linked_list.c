#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

void main(void)
{
    struct node *head = NULL;
    struct node *element = NULL;
    struct node *nav = NULL;
    int i =0;

    head = malloc(sizeof(struct node));
    head->data = 0;
    nav = head;
    element = head;
    for(i =1 ;i <= 5; i++)
    {
        nav->next = malloc(sizeof(struct node) );
        nav->data = i;
        nav = nav->next; 
 
        if(i == 5)
        {
            nav->next =NULL;
        }
    }
   while(element != NULL)
   {
        printf("The data is : %d \r\n", element->data);
        element = element->next;
   }
}



