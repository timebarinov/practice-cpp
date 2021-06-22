#include <iostream>
using namespace std;

void CountSort(int a[], int n) {
    int buf[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    for (int i = 0; i < n; i++) {
        buf[a[i]]++;
    }
    int i = 0;
    for (int j = 0; j < 10; j++) {
        for (int k = 0; k < buf[j]; k++) {
            a[i] = j;
            i++;
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
    CountSort(arr, 10);
    Print(arr);
    return 0;
}