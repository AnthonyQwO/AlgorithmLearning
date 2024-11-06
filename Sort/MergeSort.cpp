#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r) { // [l, r)
    vector<int> temp(arr.begin() + l, arr.begin() + r);
    reverse(temp.begin() + m - l, temp.begin() + r - l);
    for( int i = l, j = r - 1, k = l ; k < r; k++) {
        if(temp[i - l] < temp[j - l])
            arr[k] = temp[i++  - l];       
        else
            arr[k]=temp[j-- - l];
    }
}

void mergeSort(vector<int> &arr, int l, int r) { // [l, r)
    if(r - l >= 2) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m, r);
        merge(arr, l, m, r);
    }
}

int main() {
    vector<int> arr = {INT32_MAX, 12, 2313, -121212, 3232, 1, 2, 0, 22, 4};
    mergeSort(arr, 0, 10);
    for(int i: arr) cout << i << ' ';
}
