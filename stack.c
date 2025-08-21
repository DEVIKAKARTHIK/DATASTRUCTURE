#include<stdio.h>
# define max 5
int stack[max],top=-1;
void push(int val)
{
    if(top==max-1)
    {
        printf("Stack is overflow");
    }
    else
    {
        top++;
        stack[top]=val;
        printf("\nElement in stack inserted=%d",val);
    }

}
void pop()
{
    if(top==-1)
    {
        printf("Stack is underflow");
    }
    else
    {
        int item=stack[top];
        top--;
        printf("\nElement popped=%d",item);
    }
}
void display()
{
    for(int i=top;i>=0;i--)
    {
        printf("\nElements in stack: %d\t",stack[i]);
    }
}
int main()
{
  int elem,choice;
  char ch;
  do
  {
  printf("Select the stack operation");
  printf("\n1. Push");
  printf("\n2. Pop");
  printf("\n3. Display");
  printf("\n4. Exit");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
        printf("Enter the element to be inserted=");
        scanf("%d",&elem);
        push(elem);
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    case 4:
        return 0;
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    
        
    printf("\nDo you want to continue? Y / N");
    scanf(" %c",&ch);
}while(ch=='Y' || ch=='y');
return 0;

}


