#include <iostream>
using namespace std;

// Partition function using the first element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low];      // First element as pivot
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);  // Put pivot in its correct place
    return j;
}

// Recursive Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);   // Sort left part
        quickSort(arr, pivotIndex + 1, high);  // Sort right part
    }
}

// Print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main() {
    int arr[] = {24, 9, 29, 14, 19, 27};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    printArray(arr, n);

    return 0;
}
