# Sort

## Merge sort

```cpp
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r) { //[l, r)
    // Function to merge two sorted halves of the array
    vector<int> temp = arr;
    reverse(temp.begin() + m, temp.begin() + r);
    for (int i = l, j = r - 1, k = l; k < r; k++) {
        if (temp[i] < temp[j])
            arr[k] = temp[i++];
        else
            arr[k] = temp[j--];
    }
}

void merge_sort(vector<int> &arr, int l, int r) { //[l, r)
    // Recursive function to perform merge sort on the array
    if (r - l >= 2) {
        int m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m, r);
        merge(arr, l, m, r);
    }
}

int main() {
    // Main function
    vector<int> arr = {INT32_MAX, 12, 2313, -121212, 3232, 1, 2, 0, 22, 4};

    // Sorting the array using merge sort
    merge_sort(arr, 0, 10);

    // Printing the sorted array
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
}
```

### Explanation:

- The program implements the merge sort algorithm to sort a given array of integers in ascending order.

- The `merge` function is responsible for merging two sorted halves of the array. It uses an auxiliary array `temp` and iterates through the halves, comparing and merging them back into the original array.

- The `merge_sort` function recursively divides the array into halves until the base case (single element or empty array) is reached. Then, it calls the `merge` function to combine the sorted halves.

- The `main` function initializes an array with unsorted integers, calls `merge_sort` to sort it, and then prints the sorted array.

Note: The `[l, r)` notation is used to denote that the range is inclusive of `l` and exclusive of `r`.

## Quick sort

```cpp
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
```

### Explanation:

- The program implements the quicksort algorithm to sort a given array of integers in ascending order.

- The `partition` function is responsible for selecting a pivot element and partitioning the array into two halves, such that elements smaller than the pivot are on the left, and elements greater than the pivot are on the right. It returns the index of the pivot.

- The `quick_sort` function recursively applies quicksort on the subarrays formed by the partitioning until the base case (single element or empty array) is reached.

- The `main` function initializes an array with unsorted integers, calls `quick_sort` to sort it, and then prints the sorted array.

Note: The `[l, r]` notation is used to denote that the range is inclusive of both `l` and `r`.

## Shell sort

```cpp
#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr, int l, int r, int gap) { //[l, r)
    // Function to perform insertion sort with a specified gap
    for (int i = l, j; i < r; i += gap) {
        int t = arr[i];
        for (j = i - gap; j >= 0; j -= gap) {
            if (arr[j] < t)
                break;
            arr[j + gap] = arr[j];
        }
        swap(arr[j + gap], t);
    }
}

void shell_sort(vector<int> &arr, int l, int r) { //[l, r)
    // Function to perform shell sort on the array
    int n = r - l, count = 0;
    queue<int> interval;

    // Generate intervals for shell sort
    while (n / 2 > 0) {
        interval.push(n / 2);
        n = n / 2;
    }

    // Perform insertion sort with specified intervals
    while (!interval.empty()) {
        insertion_sort(arr, l, r, interval.front());
        interval.pop();
    }
}

int main() {
    // Main function
    vector<int> arr = {3};

    // Sorting the array using shell sort
    shell_sort(arr, 0, arr.size());

    // Printing the sorted array
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << ' ';
}
```

### Explanation:

- The program implements the shell sort algorithm to sort a given array of integers in ascending order.

- The `insertion_sort` function performs an insertion sort with a specified gap. It iterates through the array and inserts each element into its correct position within its subarray defined by the gap.

- The `shell_sort` function generates intervals for shell sort and applies insertion sort with these intervals until the array is sorted.

- The `main` function initializes an array with unsorted integers (in this case, a single element), calls `shell_sort` to sort it, and then prints the sorted array. Shell sort is particularly useful for improving the performance of insertion sort on partially sorted arrays.

Note: The `[l, r)` notation is used to denote that the range is inclusive of `l` and exclusive of `r`.
