#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
int size = 0;

// Function declarations
void insertion();
void deletion();
void display(struct node *ptr);

// Insertion functions
void ins_beginning(struct node *newnode);
void ins_end(struct node *newnode);
void ins_anypos(struct node *newnode);

// Deletion functions
void del_beginning();
void del_end();
void del_anypos();

int main() {
    int choice;
    while (1) {
        printf("Enter 0 to display, 1 to insert, 2 to delete or 5 to exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                display(head);
                break;
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

// Display list
void display(struct node *ptr) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    struct node *temp = ptr;
    do {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != head)
            printf(" -> ");
    } while (temp != head);
    printf("\n");
}

// Insert at beginning
void ins_beginning(struct node *newnode) {
    struct node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newnode;
    newnode->next = head;
    head = newnode;
}

// Insert at end
void ins_end(struct node *newnode) {
    struct node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newnode;
    newnode->next = head;
}

// Insert at any position
void ins_anypos(struct node *newnode) {
    int position;
    printf("Enter the position to insert into (1 to %d): ", size);
    scanf("%d", &position);

    if (position < 1 || position > size) {
        printf("Invalid position!\n");
        free(newnode);
        return;
    }

    if (position == 1) {
        ins_beginning(newnode);
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < position - 1; i++)
        temp = temp->next;

    newnode->next = temp->next;
    temp->next = newnode;
}

// Insertion main
void insertion() {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Element: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        size++;
        display(head);
        return;
    }

    int type;
    printf("Enter 0 for beginning, 1 for end, 2 for any position: ");
    scanf("%d", &type);
    switch (type) {
        case 0:
            ins_beginning(newnode);
            break;
        case 1:
            ins_end(newnode);
            break;
        case 2:
            ins_anypos(newnode);
            break;
        default:
            printf("Invalid type!\n");
            free(newnode);
            return;
    }
    size++;
    display(head);
}

// Delete from beginning
void del_beginning() {
    struct node *temp = head, *delnode = head;
    while (temp->next != head)
        temp = temp->next;

    head = head->next;
    temp->next = head;
    free(delnode);
}

// Delete from end
void del_end() {
    struct node *temp = head, *delnode;
    while (temp->next->next != head)
        temp = temp->next;
    delnode = temp->next;
    temp->next = head;
    free(delnode);
}

// Delete from any position
void del_anypos() {
    int position;
    printf("Enter position to delete (1 to %d): ", size);
    scanf("%d", &position);

    if (position < 1 || position > size) {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1) {
        del_beginning();
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < position - 1; i++)
        temp = temp->next;

    struct node *delnode = temp->next;
    temp->next = delnode->next;
    free(delnode);
}

// Deletion main
void deletion() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        size = 0;
        display(head);
        return;
    }

    int type;
    printf("Enter 0 to delete from beginning, 1 from end, 2 from any position: ");
    scanf("%d", &type);
    switch (type) {
        case 0:
            del_beginning();
            break;
        case 1:
            del_end();
            break;
        case 2:
            del_anypos();
            break;
        default:
            printf("Invalid type!\n");
            return;
    }
    size--;
    display(head);
}
