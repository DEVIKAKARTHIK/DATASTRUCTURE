#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *rear=NULL;
struct node *front=NULL;
//enqueue
void enqueue(int elem)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\nMemory allocation failed");
    }
     newnode->data=elem;
     newnode->next=NULL;
    if(rear==NULL)
    {
        front=rear=newnode;
    }
   else{
    rear->next=newnode;
    rear=newnode;
   }
}
//dequeue
void dequeue()
{
    struct node *temp=front;
    if(front==NULL)
    {
        printf("\n queue is empty");
    }
    int item=temp->data;
    front=front->next;
    printf("\ndequed elem=%d",item);
    free(temp);
    
}
//display
void display()
{
    struct node *temp=front;
    if(front==NULL)
    {
        printf("\n Queue is empty");
        return;
    }
    printf("Elements in queue=");
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    
}
int main()
{
    int choice,elem;
    char ch;
    do
    {
        printf("\nEnter the operation=");
        printf("\n1.enqueue\n2.dequeue\n3.display=");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nEnter the element to be inserted=");
                   scanf("%d",&elem);
                   enqueue(elem);
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            default:printf("\n Invalid operation");
        }
        printf("Do you want to continue y or n=");
        scanf(" %c",&ch);

    } while(ch=='y'||ch=='Y');
   return 0; 
}