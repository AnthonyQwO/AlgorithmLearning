#include <bits/stdc++.h>
using namespace std;

void merge( vector<int> &arr, int l, int m, int r ) { //[l,r)
    vector<int> temp = arr;
    reverse(temp.begin() + m, temp.begin() + r);
    for( int i=l, j=r-1, k=l ; k < r ; k++ ) {
        if( temp[i] < temp[j] )
            arr[k]=temp[i++];       
        else
            arr[k]=temp[j--];
    }
}

void merge_sort( vector<int> &arr, int l, int r ) { //[l,r)
    if( r-l >=2 ) {
        int m = (l+r)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m,r);
        merge(arr,l,m,r);
    }
}

int main()
{
    vector<int> arr={INT32_MAX,12,2313,-121212,3232,1,2,0,22,4};
    merge_sort(arr,0,10);
    for( int i=0 ; i < arr.size() ; i++ )
        cout<<arr[i]<<' ';

}
