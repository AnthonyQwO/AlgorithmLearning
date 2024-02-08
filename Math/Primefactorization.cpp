#include <bits/stdc++.h>
#define int long long
using namespace std;

int add(int x,int y,int mod) {
    return (x+y)%mod;
}
int mul(int x,int y,int mod){
	int ret=x*y-(int)((long double)x/mod*y)*mod;
	// int ret=x*y-(int)((long double)x*y/mod+0.5)*mod;
	return ret<0?ret+mod:ret;
}
// does not work when n is prime  O(n^(1/4))
int f(int x, int mod){ return add(mul(x,x,mod),1,mod); }
int pointard_rho(int n) {
	if(!(n&1)) return 2;
  while(true){
    int y=2, x=rand()%(n-1)+1, res=1;
    for(int sz=2; res==1; sz*=2) {
      for(int i=0; i<sz && res<=1; i++) {
        x = f(x, n);
        res = __gcd((int)abs((int)x-y),(int)n);
      }
      y = x;
    }
    if (res!=0 && res!=n) return res;
} }
// n < 4,759,123,141        3 :  2, 7, 61
// n < 1,122,004,669,633    4 :  2, 13, 23, 1662803
// n < 3,474,749,660,383          6 :  pirmes <= 13
// n < 2^64                       7 :
// 2, 325, 9375, 28178, 450775, 9780504, 1795265022
// Make sure testing integer is in range [2, n−2] if
// you want to use magic.
int magic[]={2, 325, 9375, 28178, 450775, 9780504, 1795265022};
int qpow( int n, int k, int mod ) {
    int res=1;
    while( k ) {
        if( k&1 ) res=res*n%mod;
        n=n*n%mod, k>>=1;
    }
    return res;
}
bool witness(int a,int n,int u,int t){
	if(!a) return 0;
	int x=qpow(a,u,n);
	for(int i=0;i<t;i++) {
		int nx=mul(x,x,n);
		if(nx==1&&x!=1&&x!=n-1) return 1;
		x=nx;
	}
	return x!=1;
}
bool miinter_rabin(int n) {
	int s=(7);
	// iterate s times of witness on n
	if(n<2) return 0;
	if(!(n&1)) return n == 2;
	int u=n-1; int t=0;
	// n-1 = u*2^t
	while(!(u&1)) u>>=1, t++;
	while(s--){
		int a=magic[s]%n;
		if(witness(a,n,u,t)) return 0;
	}
	return 1;
}

vector<int> ret;
void f( int n ) {
    if( miinter_rabin(n) ) {
        ret.push_back(n);
        return;
    }
    int x=pointard_rho(n);
    f(x), f(n/x);
}

signed main()
{
    long long n;
    while( cin>>n ) {
        f(n);
        for( long long i : ret ) cout<<i<<' ';
        cout<<'\n';
        ret.clear();
        cout<<"maximum\n"<<INT64_MAX<<'\n';
    }
}