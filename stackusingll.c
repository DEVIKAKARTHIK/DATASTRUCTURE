#include<stdio.h>
 #include<stdlib.h>
#define size 5
struct node {
    int data;
    struct node* next;
};
struct node *top=NULL;
void push(int elem)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
      printf("\n Stack is Overflow(Memmory allocation failed)");
    }
        newnode->data=elem;
        newnode->next=top;
        top=newnode;
}
void pop()
{
   if(top==NULL)
    {
        printf("Stack is Empty");
    }
   
        struct node *temp=top;
        int item=top->data;
        top=top->next;
        printf("Popped element is %d\n",item);
        free(temp);
    
}
void display()
{ 
    struct node *temp=top;
    if(top==NULL)
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("Stack elements are:\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }

}
int main()
{
    int choice,elem;
    char ch;
    do
    {
        printf("\nEnter the operation=");
        printf("\n1.push\n2.pop\n3.display=");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("\nEnter the element to be inserted=");
                   scanf("%d",&elem);
                   push(elem);
                   break;
            case 2:pop();
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