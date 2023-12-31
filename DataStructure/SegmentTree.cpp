#include <bits/stdc++.h>
#define int long long
#define cl(x) (x*2)
#define cr(x) (x*2+1)
using namespace std;

struct segmentTree {
    int n;
    vector<int> seg, tag, cov;
    segmentTree( int _n ): n(_n) {
        seg=tag=cov=vector<int>(n*4,0);
    }
    void push( int i, int L, int R ) {
        if( cov[i] ) {
            seg[i]=cov[i]*(R-L+1);
            if( L < R ) {
                cov[cl(i)]=cov[cr(i)]=cov[i];
                tag[cl(i)]=tag[cr(i)]=0;
            }
            cov[i]=0;
        }
        if( tag[i] ) {
            seg[i]+=tag[i]*(R-L+1);
            if( L < R ) {
                tag[cl(i)]+=tag[i];
                tag[cr(i)]+=tag[i];
            }
            tag[i]=0;
        }
    }
    void pull( int i, int L, int R ) {
        if( L >= R ) return;
        int mid=(L+R)>>1;
        push(cl(i),L,mid);
        push(cr(i),mid+1,R);
        seg[i]=seg[cl(i)]+seg[cr(i)];
    }
    void build( vector<int>& arr, int i=1, int L=1, int R=-1 ) {
        if( R == -1 ) R=n;
        if( L == R ) {
            seg[i]=arr[L];
            return;
        }
        int mid=(L+R)>>1;
        build(arr,cl(i),L,mid);
        build(arr,cr(i),mid+1,R);
        pull(i,L,R);
    }
    int query( int rL, int rR, int i=1, int L=1, int R=-1 ) {
        if( R == -1 ) R=n;
        push(i,L,R);
        if( rL <= L && R <= rR ) return seg[i];
        int mid=(L+R)>>1, ret=0;
        if( rL <= mid ) ret+=query(rL,rR,cl(i),L,mid);
        if( mid < rR ) ret+=query(rL,rR,cr(i),mid+1,R);
        return ret;
    }
    void update( int rL, int rR, int val, int i=1, int L=1, int R=-1 ) {
        if( R == -1 ) R=n;
        push(i,L,R);
        if( rL <= L && R <= rR ) {
            tag[i]=val;
            return;
        }
        int mid=(L+R)>>1;
        if( rL <= mid ) update(rL,rR,val,cl(i),L,mid);
        if( mid < rR ) update(rL,rR,val,cr(i),mid+1,R);
        pull(i,L,R);
    }
    void cover( int rL, int rR, int val, int i=1, int L=1, int R=-1 ) {
        if( R == -1 ) R=n;
        push(i,L,R);
        if( rL <= L && R <= rR ) {
            cov[i]=val;
            return;
        }
        int mid=(L+R)>>1;
        if( rL <= mid ) cover(rL,rR,val,cl(i),L,mid);
        if( mid < rR ) cover(rL,rR,val,cr(i),mid+1,R);
        pull(i,L,R);
    }
};


signed main()
{
    int n, q;
    cin>>n;
    segmentTree SMT(n);
    vector<int> arr(n+1);
    for( int i=1 ; i <= n ; i++ ) cin>>arr[i];
    SMT.build(arr);
    cin>>q;
    for( int i=0 ; i < q ; i++ ) {
        int a, b, c, d;
        cin>>a>>b>>c;
        if( a == 1 ) {
            cin>>d;
            SMT.update(b,c,d);
        }
        else if( a == 3 ) {
            cin>>d;
            //SMT.cover(b,c,d);
        }
        else cout<<SMT.query(b,c)<<'\n';
    }
}