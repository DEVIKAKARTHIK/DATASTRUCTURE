#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;
void insert()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory allocation failed\n");
    }
    printf("Enter the data:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}
void insertend()
{
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        
        }
        temp->next=newnode;
}

}
// void insertinter()
// {
//     struct node *newnode,*temp;
//     newnode=(struct node *)malloc(sizeof(struct node));
//     int pos;
//     if (newnode == NULL)
//     {
//         printf("Memory allocation failed\n");
//         return;
//     }
//     printf("Enter the position where you want to insert the node:");
//     scanf("%d",&pos);
//     printf("Enter the data: ");
//     scanf("%d", &newnode->data);

//     temp=head;
//     while(temp->next<pos)
//     {
//         newnode->next=temp->next;
//         temp->next=newnode;
//     }

// }

void display()
{
    struct node *temp=head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void deleteb()
{
   if(head==NULL)
   {
        printf("List is empty\n");
        return;
   }
    struct node *temp=head;
    head=temp->next;
    printf("Node deleted from the end is:%d\n",temp->data);
    free(temp);
}
void delend()
{
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp=head;
    if (head->next == NULL) {
        printf("Node deleted from the end is: %d\n", temp->data);
        free(head);
        head = NULL;
        return;
    }
    struct node *prevnode = NULL;
    while(temp->next!=NULL)
    {
        prevnode=temp;
        temp=temp->next;
    }prevnode->next = NULL;
    printf("Node deleted from the end is: %d\n", temp->data);
    free(temp);
    
    


}
int search(int elem)
{
    
    struct node* temp=head;
    int count=1;
    while(temp!=NULL)
    {
        
        if(temp->data==elem)
        {
            return count;
        }
        
        temp=temp->next;
        count++;
    }
    return -1;

}
struct node1
{
    int data1;
    struct node1 *next1;

};
struct node1 *head1=NULL;
void merge()
{
    struct node *temp;
    struct node1 *newnode1,*head1;
    newnode1=(struct node1 *)malloc(sizeof(struct node1));

    temp=head;
    while(temp->next!=NULL)
    {

        temp=temp->next;
    }
    temp->next=head1;
}

int main()
{
    int elem,n,pos,choice;
  char ch;
  do
  {
  printf("\nSelect the linkedlist operation");
  printf("\n1. Insertion at the beginning");
  printf("\n2. Insertion at the end");
  printf("\n3. Deletion at the beginning");
  printf("\n4. Deletion at the end");
  printf("\n5. Display");
  printf("\n6. Search");
  printf("\n7. Merge");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
    printf("Enter the number of elements to be inserted:");
    scanf("%d",&n);
     for(int i=0;i<n;i++)
     {
        insert();
     }
     break;
     
     case 2:
        insertend();
        break;
    
    case 3:
        deleteb();
        break;
    
    case 4:
        delend();
        break;
    
    case 5:
        display();
        break;
    
    case 6:
        printf("Enter the element to be searched:");
        scanf("%d",&elem);
        pos=search(elem);
        if(pos==-1)
        {
            printf("Element not found");
        }
        else
        {
            printf("Element found at index:%d",pos);
        }
        break;
case 7:
      merge();
      break;
 default:
        printf("Invalid choice!!!");
        break;
  }
printf("\nDo you want to continue? Y / N");
    scanf(" %c",&ch);
}while(ch=='Y' || ch=='y');
return 0;

}