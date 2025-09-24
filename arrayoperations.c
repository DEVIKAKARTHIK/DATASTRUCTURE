#include <stdio.h>

#define SIZE 100

int main() {
    int arr[SIZE], n, choice, pos, elem, i, found;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nArray Operations Menu:\n");
        printf("1. Traverse\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Traverse
                printf("Array elements: ");
                for(i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 2: // Insert
                if(n >= SIZE) {
                    printf("Array is full, cannot insert.\n");
                } else {
                    printf("Enter position (0-%d): ", n);
                    scanf("%d", &pos);
                    printf("Enter element to insert: ");
                    scanf("%d", &elem);

                    for(i = n; i > pos; i--) {
                        arr[i] = arr[i-1];
                    }
                    arr[pos] = elem;
                    n++;
                    printf("Element inserted.\n");
                }
                break;

            case 3: // Delete
                if(n <= 0) {
                    printf("Array is empty, nothing to delete.\n");
                } else {
                    printf("Enter position (0-%d): ", n-1);
                    scanf("%d", &pos);

                    if(pos < 0 || pos >= n) {
                        printf("Invalid position.\n");
                    } else {
                        for(i = pos; i < n-1; i++) {
                            arr[i] = arr[i+1];
                        }
                        n--;
                        printf("Element deleted.\n");
                    }
                }
                break;

            case 4: // Search
                printf("Enter element to search: ");
                scanf("%d", &elem);
                found = 0;
                for(i = 0; i < n; i++) {
                    if(arr[i] == elem) {
                        printf("Element %d found at position %d\n", elem, i);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("Element not found.\n");
                }
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice, try again.\n");
        }
    } while(choice != 5);

    return 0;
}
