#include <stdio.h>

int n = 0; // Global size of the array

void takeInput(int arr[], int n) {
    // Taking input 
    for (int i = 0; i < n; i++) {
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }
}

// Function to update an element 
void update(int arr[], int index, int value) {
    if (index < 0 || index >= n) {
        printf("Update failed: Invalid index.\n");
        return;
    }
    arr[index] = value;
}

// Function to delete an element at a given index
void deleteElement(int arr[], int index) {
    if (index < 0 || index >= n) {
        printf("Delete failed: Invalid index.\n");
        return;
    }
    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

// Function to sort the array in ascending or descending order
void selectionSort(int arr[], int ascending) {
    for (int i = 0; i < n - 1; i++) {
        int targetIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (ascending) {
                if (arr[j] < arr[targetIndex]) {
                    targetIndex = j;
                }
            } else {
                if (arr[j] > arr[targetIndex]) {
                    targetIndex = j;
                }
            }
        }
        int temp = arr[i];
        arr[i] = arr[targetIndex];
        arr[targetIndex] = temp;
    }
}

// Function to search for an element in the array
void search(int arr[], int value) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            printf("Element found at index: %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element not found.\n");
    }
}

// Function to display the array
void display(int arr[]) {
    printf("Current Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];  
    int choice, index, value, order;

    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert\n");
        printf("2. Update\n");
        printf("3. Delete\n");
        printf("4. Sort\n");
        printf("5. Search\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                
                printf("Enter the number of elements in the array: ");
                scanf("%d", &n);

                if (n <= 0 || n > 100) {
                    printf("Invalid number of elements. It should be between 1 and 100.\n");
                    n = 0;
                    break;
                }

                
                takeInput(arr, n);
                display(arr); 
                break;

            case 2:
                printf("Enter index to update: ");
                scanf("%d", &index);
                printf("Enter new value: ");
                scanf("%d", &value);
                update(arr, index, value);
                display(arr);  
                break;

            case 3:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteElement(arr, index);
                display(arr);  
                break;

            case 4:
                printf("Choose sorting order:\n");
                printf("1. Ascending\n");
                printf("2. Descending\n");
                printf("Enter your choice: ");
                scanf("%d", &order);
                if (order == 1) {
                    selectionSort(arr, 1); // Sort Ascending
                    printf("Array sorted in Ascending order.\n");
                } else if (order == 2) {
                    selectionSort(arr, 0); // Sort Descending
                    printf("Array sorted in Descending order.\n");
                } else {
                    printf("Invalid sorting order.\n");
                }
                display(arr);  // Display array after sorting
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(arr, value);
                break;

            case 6:
                display(arr);  // Display current array
                break;

            case 7:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
