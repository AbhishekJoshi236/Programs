// In this code we are searching for a key entered by an user and if found then deleting the respective node.

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
    int flag=0;
    while(temp!=NULL)
    {
        if( (temp->data) == key)
        {
            if(flag==0)
            {
                printf("\nKEY FOUND.\n");
                flag=1;
            }

            //Condition for the First Element.
            if( ( (temp->data) == key) && (temp==start) )
            {
                
                start=temp->next;
                start->prev=NULL;
                free(temp);
            }
            
            //Condition for the Last Element.
            else if( ( (temp->data) == key) && (temp->next==NULL) )
            {
                
                temp->prev->next=temp->next;
                free(temp);
            }
            
            else
            {
                
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(temp);
            }
        }

        temp=temp->next;
    }

    if(flag==1)
    {
        display();
        exit(0);
    }
    printf("\nKEY NOT FOUND.\n");
}

int main()
{
    int key;

    //Creating Linked List
    createdll(10);
    createdll(20);
    createdll(10);
    createdll(40);
    createdll(50);
    createdll(30);
    createdll(40);
    display();                      //Displaying Linked List Before Updation.

    printf("Enter a Key: ");
    scanf("%d",&key);

    searchkey(key);
  
    return 0;
}
