#include <iostream>
using namespace std;

void BubbleSort(int a[], int n) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i+1]) {
                int tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                sorted = false;                
            }
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
    int arr[10] = { 4, 8, 1, 3, 2, 9, 10, 5, 7, 6};
    BubbleSort(arr, 10);
    Print(arr);
    return 0;
}