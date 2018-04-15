#include <stdio.h>
#include <stdlib.h>

enum
{
    INSERT = 1,
    DELETE,
    PRINT, 
    END
};
struct node 
{
    int data;
    struct node *next;
};

void print_element(struct node *head);
int perform_action(int action , struct node *input);
void main(void)
{
    struct node *head = NULL;
    int action = 1;

    head = malloc(sizeof(struct node));
    if(!head)
    {
        printf("\r\n Error in memory allocation.");
        return;
    }
    head->data = 0;


    while(1)
    {
        printf("Enter a opeation to perform \n 1.Insert \n 2. Delete\n 3.print element \n ");
        scanf("%d" , &action);
        if(action < INSERT && action > END)
        {
            printf("Invalid input");
            return ;
        }

        perform_action(action , head);
    }
}

int perform_action(int action , struct node *head)
{
    struct node *element = NULL;
    struct node *nav = NULL;
    int i =0;
    int input = 0 , count =0;

    element = head;

    switch(action)
    {
        case INSERT:
            while(element != NULL)
            {
                printf("The data is : %d \r\n", element->data);
                nav = element;
                element = element->next;
            }
            printf("Enter the number\r\n");
            scanf("%d" , &input);
            /* need to add validation for input 
               to be integer only */

            nav->next = malloc(sizeof(struct node) );
            if(!nav->next)
            {
                printf("\r\n Memory allocaiotn failure ");
                return 0;
            }
            nav->data = input;
            nav = nav->next; 
            nav->next = NULL;
            print_element(head);
            break;
        case DELETE:
            printf("Enter the number to delete\r\n");
            scanf("%d" , &input);
            while(element != NULL)
            {

                /* only one element */
                if(element->next == NULL)
                {
                    printf("Only one element available. Cannot delete");
                    return 0;
                }
                else 
                {
                    if(element->data == input)
                    {
                        nav->next = element->next;
                        printf("Match found \n");
                        free(element);
                        break;
                    }
                    nav= element;
                    element = element->next;
                }
            }
            print_element(head);
            break;
        case PRINT:
            print_element(head);
            break;
    }

}

void print_element(struct node *head)
{
    struct node *element = head;
    while(element != NULL)
    {
        printf("The data is : %d \r\n", element->data);
        element = element->next;
    }
}
