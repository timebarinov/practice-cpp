#include <iostream>
#include <vector>
using namespace std;

template<typename InputIt, typename OutputIt>
OutputIt Merge(InputIt first1, InputIt last1, InputIt first2, InputIt last2, OutputIt result) {
    for (; first1 != last1; result++) {
        if (first2 == last2) {
            while (first1 != last1) {
                *result = *first1;
                result++;
                first1++;
            }
            return result;
        }
        if (*first1 < *first2) {
            *result = *first1;
            first1++;
        }
        else {
            *result = *first2;
            first2++;
        }
    }
    for (; first2 != last2; result++) {
        *result = *first2;
        first2++;
    }
    return result;
}

template <typename It>
void MergeSort(It range_begin, It range_end) {
    if (range_end - range_begin < 2) {
        return;
    }
    vector<typename It::value_type> elements(range_begin, range_end);
    auto mid = elements.begin() + elements.size() / 2;
    MergeSort(elements.begin(), mid);
    MergeSort(mid, elements.end());
    Merge(elements.begin(), mid, mid, elements.end(), range_begin);
}

template<class T>
void Print(const T& arr) {
    for (const auto& i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> val = { 4, 8, 1, 3, 2, 9, 0, 5, 7};
    MergeSort(val.begin(), val.end());
    Print(val);
    return 0;
}