#include <stdio.h>

void bubbleSort(int arr[], int n, int swapCount[], int *totalSwaps) {
    *totalSwaps = 0; 
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapCount[arr[j]]++; 
                swapCount[arr[j+1]]++;
                (*totalSwaps)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swapCount[], int *totalSwaps) {
    *totalSwaps = 0; 
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
        swapCount[temp]++;
        swapCount[arr[i]]++;
        (*totalSwaps)++; 
    }
}

int main() {
    int size;
    printf("Enter Size: ");
    scanf("%d", &size);
    int arr1[size];
    int arr2[size];
    for(int i = 0; i < size; i++) {
        printf("Enter Position %d: ", i+1);
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
    }
    
    int n = sizeof(arr1)/sizeof(arr1[0]);
    printf("Array before sorting: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    int swapCount[1001] = {0}; 
    int totalSwaps;

    // Bubble Sort
    bubbleSort(arr1, n, swapCount, &totalSwaps);
    printf("\nBubble Sort:\n");
    printf("Array after sorting: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
        printf("Moved: %d times\n", swapCount[arr1[i]]);
    }
    printf("Total swaps: %d\n", totalSwaps);

    // Selection Sort
    selectionSort(arr2, n, swapCount, &totalSwaps);
    printf("\nSelection Sort:\n");
    printf("Array after sorting: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
        printf("Moved: %d times\n", swapCount[arr2[i]]);
    }
    printf("Total swaps: %d\n", totalSwaps);

    return 0;
}