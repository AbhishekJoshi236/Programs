//CODE 3  Searching and deleting a KEY from the Circular Linked List.

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
    int flag=0;
    while( (temp->next)!=(tail->next) )
    {
      
        if((temp->data)==key)
        {
            if(flag==0)
            {
                printf("\nKEY FOUND\n");
                flag=1;
            }

            if(temp==(tail->next))
            {
                tail->next=temp->next;
                free(temp);
            }    
            else 
            {
                prev->next=temp->next;
                free(temp);   
            }
        }
        prev=temp;
        temp=temp->next;
        
    }
    
    if(  (temp->data)==key )
    {
        if(flag==0)
            {
                printf("\nKEY FOUND\n");
            }
        
        prev->next=tail->next;
        tail=prev;
        free(temp);
        //display();
        //exit(0);
    }
    
    if(flag==1)
    {
        display();
        exit(0);
    }

    printf("\nKEY NOT FOUND\n\n");
    
    
}
int main()
{
    int key;
    createdll(10);
    createdll(20);
    createdll(30);
    createdll(40);
    createdll(50);
    createdll(20);
    createdll(40);

    display();                                  //Displaying Linked List Before Upation.
    
    
    printf("\n\nEnter a Key:  ");
    scanf("%d",&key);
    searchkey(key);


    return 0;
}
