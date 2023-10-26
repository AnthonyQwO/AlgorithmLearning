#include <bits/stdc++.h>
using namespace std;

void insertion_sort( vector<int> &arr, int l, int r, int gap ) { //[l,r)
    for( int i=l, j ; i < r ; i+=gap ) {
        int t=arr[i];
        for( j=i-gap ; j >= 0 ; j-=gap ) {
            if( arr[j] < t )
                break;
            arr[j+gap]=arr[j];
        }
        swap(arr[j+gap],t);
    }
}

void shell_sort( vector<int> &arr, int l, int r ) { //[l,r)
    int n=r-l,count=0;
    queue<int> interval;
    while( n/2 > 0 ) {
        interval.push(n/2);
        n=n/2;
    }
    
    while ( !interval.empty() ) {
        insertion_sort(arr,l,r,interval.front());
        interval.pop();
    }    
}

int main()
{
    vector<int> arr={3};
    shell_sort(arr,0,arr.size());
    for( int i=0 ; i < arr.size() ; i++ )
        cout<<arr[i]<<' ';
}
