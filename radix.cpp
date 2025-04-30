#include <iostream>
#include <vector>
using namespace std;

// A utility function to get the maximum number in the array
int getMax(const vector<int>& arr) {
    int maxVal = arr[0];
    for (int num : arr)
        if (num > maxVal)
            maxVal = num;
    return maxVal;
}

// A function to do counting sort based on the digit represented by exp
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // output array
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual position
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array (stable sort)
    for (int i = n - 1; i >= 0; i--) {
        int idx = (arr[i] / exp) % 10;
        output[count[idx] - 1] = arr[i];
        count[idx]--;
    }

    // Copy the output array back to arr[]
    arr = output;
}

// The main function to that sorts arr[] using Radix Sort
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);

    // Do counting sort for every digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

// Utility function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// Driver code
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Original array:\n";
    printArray(arr);

    radixSort(arr);

    cout << "Sorted array:\n";
    printArray(arr);
    return 0;
}
