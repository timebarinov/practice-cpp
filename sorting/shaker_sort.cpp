#include <iostream>
using namespace std;

void ShakerSort(int a[], int n) {
    if (n == 0) {
        return;
    }
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        for (int i = right; i > left; i--) {
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
            }
        }
        left++;
        for (int i = left; i < right; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
            }
        }
        right--;
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
    ShakerSort(arr, 10);
    Print(arr);
    return 0;
}