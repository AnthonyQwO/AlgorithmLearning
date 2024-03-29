#include <bits/stdc++.h>
#define lowbit(x) (x&-x)
using namespace std;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int _n):n(_n), bit(n+1) {}
    void update( int x, int val ) {
        for(;x <= n; x += lowbit(x)) bit[x] += val;
    }
    void range_update( int L, int R, int val ) {
        update(L,val), update(R+1,-val);        
    }
    int query( int x ) {
        int res = 0;
        for(;x; x -= lowbit(x)) res += bit[x];
        return res;
    }
    int range_query( int L, int R ) {
        return query(R)-query(L-1);
    }
};