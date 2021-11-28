//CODE 3  Searching and deleting a KEY from the Circular Linked List.
// Assumption: All elements in the LL are unique.

#include <stdio.h>
#include <stdlib.h>

typedef struct node_type 
{
    int data;
    struct node_type *next;
}node;


node *tail;


void createdll (int value)
{
    node *newnode;
    newnode=(node*)malloc(sizeof(int));
    newnode->data=value;
    newnode->next=NULL;
    
    if(tail==NULL)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}


void display()
{
    printf("\nDisplaying Linked List\n");
    node *temp=tail->next;
    while((temp->next)!=(tail->next))
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
        printf("%d ",temp->data);  
        printf("\n");
}


void searchkey(int key)
{
    node *temp=tail->next;
    node *prev=tail->next;
    while( (temp->next)!=(tail->next) )
    {
      
        if((temp->data)==key)
        {
            if(temp==(tail->next))
            {
                printf("\nKEY FOUND\n");
                tail->next=temp->next;

                free(temp);
                display();
                exit(0);
            }
                    
            if(temp!=tail)
            {
                printf("\nKEY FOUND\n");
                prev->next=temp->next;

                free(temp);
                display();
                exit(0);
            }
        }
        prev=temp;
        temp=temp->next;
        
    }
    
    if(  ((temp->data)==key) && (temp==tail) )
    {
        printf("\nKEY FOUND\n");
        prev->next=tail->next;
        tail=prev;
        free(temp);
        display();
        exit(0);
    }
    else
    {
        printf("\nKEY NOT FOUND\n\n");
    }
    
}
int main()
{
    int key;
    createdll(10);
    createdll(20);
    createdll(30);
    createdll(40);
    createdll(50);
    
    display();                                  //Displaying Linked List Before Upation.
    
    
    printf("\n\nEnter a Key:  ");
    scanf("%d",&key);
    searchkey(key);

   


    return 0;
}
