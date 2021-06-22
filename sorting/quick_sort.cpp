#include <iostream>
#include <vector>
using namespace std;

int Partition(vector<int>& values, int first, int last) {
    int left = first;
    int right = values[last];
    for (int i = first; i < last; i++) {
        if (values[i] <= right) {
            swap(values[i], values[left]);
            left++;
        }
    }
    swap(values[left], values[last]);
    return left;
}

void QuickSort(vector<int>& values, int first, int last) {
    if (first < last) {
        int pivot = Partition(values, first, last);
        QuickSort(values, first, pivot - 1);
        QuickSort(values, pivot + 1, last);
    }
}

void QuickSort(vector<int>& values) {
    if (!values.empty()) {
        QuickSort(values, 0, values.size() - 1);
    }
}

template<class T>
void Print(const T& arr) {
    for (const auto& i : arr) {
        cout << i << " ";
    }
}

int main() {
    vector<int> val = { 4, 8, 1, 3, 2, 9, 0, 5, 7, 6};
    QuickSort(val);
    Print(val);
    return 0;
}