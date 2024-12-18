#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int l, int r) { //[l, r]
    // Function to partition the array and return the index of the pivot
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] < arr[r]) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[++i], arr[r]);
    return i;
}

void quick_sort(vector<int> &arr, int l, int r) { //[l, r)
    // Recursive function to perform quicksort on the array
    if (l < r) {
        int m = partition(arr, l, r - 1);
        quick_sort(arr, l, m);
        quick_sort(arr, m + 1, r);
    }
}

int main() {
    // Main function
    vector<int> arr = {12, 2313, -121212, 3232, 1, 2, 0, 22, 4, 9, 65, INT32_MAX, INT32_MIN};

    // Sorting the array using quicksort
    quick_sort(arr, 0, arr.size());

    // Printing the sorted array
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
}
