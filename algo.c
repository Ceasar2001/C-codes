#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void bubbleSort(int arr[], int n, int *comparisons);
void insertionSort(int arr[], int n, int *comparisons);
void mergeSort(int arr[], int l, int r, int *comparisons);
void merge(int arr[], int l, int m, int r, int *comparisons);
void quickSort(int arr[], int low, int high, int *comparisons);
int partition(int arr[], int low, int high, int *comparisons);

// Function to swap two elements in an array and print the current state
void swapAndPrint(int *a, int *b, int arr[], int n) {
    int temp = *a;
    *a = *b;
    *b = temp;
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void bubbleSort(int arr[], int n, int *comparisons) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                swapAndPrint(&arr[j], &arr[j + 1], arr, n);
            }
        }
    }
}

void insertionSort(int arr[], int n, int *comparisons) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

void merge(int arr[], int l, int m, int r, int *comparisons) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, int *comparisons) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comparisons);
        mergeSort(arr, m + 1, r, comparisons);
        merge(arr, l, m, r, comparisons);
        for (int i = l; i <= r; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int partition(int arr[], int low, int high, int *comparisons) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            swapAndPrint(&arr[i], &arr[j], arr, high + 1);
        }
    }
    swapAndPrint(&arr[i + 1], &arr[high], arr, high + 1);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int *comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}



int main() {
    // Array data
    int arr[] = {2, 15, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    // Determine sorting order based on the last digit of your ID
    int id_last_digit = 2; // Change this to your actual last digit
    int increasing_order = id_last_digit % 2 != 0;

    printf("Array data: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nSorting Algorithm\n");
    printf("   1. Bubble Sort\n");
    printf("   2. Insert Sort\n");
    printf("   3. Merge Sort\n");
    printf("   4. Quick Sort\n\n");

    int choice;
    printf("Select: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nBubble Sort process\n");
            bubbleSort(arr, n, &comparisons);
            break;
        case 2:
            printf("\nInsertion Sort process\n");
            insertionSort(arr, n, &comparisons);
            break;
        case 3:
            printf("\nMerge Sort process\n");
            mergeSort(arr, 0, n - 1, &comparisons);
            break;
        case 4:
            printf("\nQuick Sort process\n");
            quickSort(arr, 0, n - 1, &comparisons);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    // Print sorted array
    printf("\nSorted array: ");
    if (increasing_order) {
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        for (int i = n - 1; i >= 0; i--) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n\n# of comparisons: %d\n", comparisons);

    return 0;
}