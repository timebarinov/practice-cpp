#include <iostream>
using namespace std;

void SelectSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        swap(a[min], a[i]);
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
    SelectSort(arr, 10);
    Print(arr);
    return 0;
}