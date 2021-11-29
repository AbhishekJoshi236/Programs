#include <stdio.h>
#include <stdlib.h>

typedef struct node_info
{
    int data;
    struct node_info *next;
    struct node_info *prev;
}node;

node *start=NULL;


void createdll (int value)
{
     node *newnode,*temp;
    newnode=(node*)malloc(sizeof(int));

    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(start==NULL)
        start=temp=newnode;
    else
    {
        temp->next=newnode;
        newnode->prev=temp;
        temp=temp->next;
    }
}


void display ()
{
    printf("\nDisplaying Doubly Linked List:  ");
    node *temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;

    }
    printf("\n\n");
}


void searchkey (int key)
{
    node *temp=start;

    while(temp!=NULL)
    {
        if( (temp->data) == key)
        {
            //Condition for the First Element.
            if( ( (temp->data) == key) && (temp==start) )
            {
                printf("\nKEY FOUND.\n");
                start=temp->next;
                start->prev=NULL;
                free(temp);
                
                display();                          //Displaying Linked List After Updation.
                exit(0);
                
            }
            
            //Condition for the Last Element.
            else if( ( (temp->data) == key) && (temp->next==NULL) )
            {
                printf("\nKEY FOUND.\n");
                temp->prev->next=temp->next;
                free(temp);
                
                display();                           //Displaying Linked List After Updation.
                exit(0);
            }
            
            else
            {
                printf("\nKEY FOUND.\n");
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(temp);
            
                display();                          //Displaying Linked List After Updation.
                exit(0);
            }
        }
        temp=temp->next;
    }
    printf("\nKEY NOT FOUND.\n");
}

int main()
{
    int key;

    //Creating Linked List
    createdll(10);
    createdll(20);
    createdll(30);
    createdll(40);
    createdll(50);
    display();              //Displaying Linked List Before Updation.

    printf("Enter a Key: ");
    scanf("%d",&key);

    searchkey(key);
  
    return 0;
}
