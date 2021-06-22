#include <iostream>
using namespace std;

void InsertSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && a[j - 1] > a[j]; j--) {
            int tmp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = tmp;
        }
    }
}

template<class T>
void Print(const T& arr) {
    for (const auto& i : arr) {
        cout << i << " ";
    }
}

int main() {
    int arr[10] = { 4, 8, 1, 3, 2, 9, 0, 5, 7, 6};
    InsertSort(arr, 10);
    Print(arr);
    return 0;
}