#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};



struct node *head = NULL;
void insert()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
    }
    printf("Enter the data:");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}

struct node *head1 = NULL;
void insertsec()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
    }
    printf("Enter the data:");
    scanf("%d", &newnode->data);
    newnode->next = head1;
    head1 = newnode;
}
void insertend()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the data:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void insertatpos(int data, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position");
        return;
    }
    if (pos == 1)
    {
        insert(data);
    }
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    temp = head;
    newnode->data = data;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Out of bound");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void display()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void displaysec()
{
    struct node *temp = head1;
    if (temp == NULL)
    {
        printf("List2 is empty\n");
        return;
    }
    printf("Second Linked List: ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void deleteb()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    head = temp->next;
    printf("Node deleted from the end is:%d\n", temp->data);
    free(temp);
}
void delend()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp = head;
    if (head->next == NULL)
    {
        printf("Node deleted from the end is: %d\n", temp->data);
        free(head);
        head = NULL;
        return;
    }
    struct node *prevnode = NULL;
    while (temp->next != NULL)
    {
        prevnode = temp;
        temp = temp->next;
    }
    prevnode->next = NULL;
    printf("Node deleted from the end is: %d\n", temp->data);
    free(temp);
}

void deleteatpos(int pos)
{
    if (pos<0 || head==NULL)
    {
        printf("Invalid position");
        return;
    }
    if (pos==1)
    {
        deleteb();
        return;
    }
    struct node *temp=head, *prev=NULL;
    for(int i=1;i<pos && temp!=NULL;i++)
    {
        prev=temp;
        temp=temp->next;
    }
    if (temp==NULL)
    {
        printf("Position out of bound");
        return;
    }
    prev->next=temp->next;
    printf("Element deleted from given position is:%d",temp->data);
    free(temp);
}

int search(int elem)
{

    struct node *temp = head;
    int count = 1;
    while (temp != NULL)
    {

        if (temp->data == elem)
        {
            return count;
        }

        temp = temp->next;
        count++;
    }
    return -1;
}


void merge()
{
   
   if(head==NULL)
   {
    head=head1;
    return;
   } 
   struct node *temp=head;
   while(temp->next!=NULL)
   {
    temp=temp->next;

   }
   temp->next=head1;
   head1=NULL;
}

void mergedisplay()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Merged Linked List: ");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int elem, n, pos, choice, data;
    char ch;
    do
    {
        printf("\nSelect the linkedlist operation");
        printf("\n1. Insertion at the beginning");
        printf("\n2. Insertion at the end");
        printf("\n3. Insertion at a given position");
        printf("\n4. Deletion at the beginning");
        printf("\n5. Deletion at the end");
        printf("\n6. Deletion at specified position");
        printf("\n7. Display");
        printf("\n8. Search");
         printf("\n9. Merge");
         printf("\n10. Insert into second linkedlist");
         printf("\n11.Display second linkedlist");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of elements to be inserted:");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                insert();
            }
            break;

        case 2:
            insertend();
            break;

        case 3:
            printf("Enter the position to be inserted:");
            scanf("%d", &pos);
            printf("Enter the element to be inserted:");
            scanf("%d", &data);
            insertatpos(data, pos);
            break;
         case 4:
            deleteb();
            break;   
        case 5:
            delend();
            break;

        case 6:
            printf("Enter the position from where element is to be deleted:");
            scanf("%d",&pos);
            deleteatpos(pos);
            break;
        case 7:
            display();
            break;

        case 8:
            printf("Enter the element to be searched:");
            scanf("%d", &elem);
            pos = search(elem);
            if (pos == -1)
            {
                printf("Element not found");
            }
            else
            {
                printf("Element found at index:%d", pos);
            }
            break;
        case 9:
              merge();
              printf("\n Merged successfully");
              mergedisplay(head);
               break;
        
        case 10:
            printf("Enter the number of elements to be inserted:");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                insertsec();
            }
            break;
        case 11:
            displaysec();
            break;
        default:
            printf("Invalid choice!!!");
            break;
        }
        printf("\nDo you want to continue? Y / N");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');
    return 0;
}