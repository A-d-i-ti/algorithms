#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

// Function to perform Bucket Sort
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 0)
        return;

    // Create n empty buckets
    vector<vector<float>> buckets(n);

    // Put array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] * n; // Index in bucket
        buckets[index].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // Concatenate all buckets into arr
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (float value : buckets[i])
            arr[idx++] = value;
    }
}

// Utility to print array
void printArray(const vector<float>& arr) {
    for (float val : arr)
        cout << val << " ";
    cout << endl;
}

// Driver code
int main() {
    vector<float> arr = {0.42, 0.32, 0.23, 0.52, 0.12};

    cout << "Original array:\n";
    printArray(arr);

    bucketSort(arr);

    cout << "Sorted array:\n";
    printArray(arr);

    return 0;
}
