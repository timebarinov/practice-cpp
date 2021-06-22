#include <iostream>
using namespace std;

void RadixSort(int* a, int n) {

    int* a0 = new int[n];
    int* a1 = new int[n];

    for (int radix = 0; radix < 32; radix++) {
        int a0_size = 0;
        int a1_size = 0;
        for (int i = 0; i < n; i++) {
            if ((a[i] & (1 << radix)) == 0) {
                a0[a0_size++] = a[i];
            }
            else {
                a1[a1_size++] = a[i];
            }
        }
        for (int i = 0; i < a0_size; i++) {
            a[i] = a0[i];
        }
        for (int i = 0; i < a1_size; i++) {
            a[a0_size + i] = a1[i];
        }
    }
    delete[] a0;
    delete[] a1;
}

template<class T>
void Print(const T& arr) {
    for (const auto& i : arr) {
        cout << i << " ";
    }
}

int main() {
    int arr[10] = { 4, 8, 1, 3, 2, 9, 0, 5, 7, 6};
    RadixSort(arr, 10);
    Print(arr);
    return 0;
}