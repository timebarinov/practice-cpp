#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Heapsort using include <algorithm>
void lib_HeapSort(vector<int>& values) {
    std::make_heap(values.begin(), values.end());
    for (auto i = values.end(); i != values.begin(); i--) {
        std::pop_heap(values.begin(), i);
    }
}

template<class T>
void Print(const T& arr) {
    for (const auto& i : arr) {
        cout << i << " ";
    }
}

void heapify(int arr[], int n, int i) {
    // Initialize largest as root
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
 
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
// Make heap (rearrange array)
void MakeHeap(int arr[], int n) {    
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}
// main function to do heap sort
void HeapSort(int arr[], int n) {
    
    MakeHeap(arr, n);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int val[] = { 4, 8, 1, 3, 2, 9, 0, 5, 7, 6};
    HeapSort(val, 10);
    Print(val);
    return 0;
}