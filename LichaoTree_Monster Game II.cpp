#pragma GCC optimize ("O3")

//#incluse <bits/stdc++.h>

#include <iostream>     // Input/output stream objects
#include <fstream>      // File stream objects
#include <sstream>      // String stream objects
#include <iomanip>      // Input/output manipulators
#include <string>       // String class and functions
#include <vector>       // Dynamic array
#include <list>         // Doubly linked list
#include <set>          // Set container
#include <map>          // Map container
#include <queue>        // Queue container
#include <stack>        // Stack container
#include <algorithm>    // Algorithms on sequences (e.g., sort, find)
#include <cmath>        // Mathematical functions
#include <ctime>        // Date and time functions
#include <cstdlib>      // General purpose functions (e.g., memory management)
#include <cstring>      // C-style string functions
#include <cctype>       // Character classification functions
#include <cassert>      // Assert function for debugging
#include <exception>    // Standard exceptions
#include <functional>   // Function objects
#include <iterator>     // Iterator classes
#include <limits>       // Numeric limits
#include <locale>       // Localization and internationalization
#include <numeric>      // Numeric operations (e.g., accumulate)
#include <random>       // Random number generators
#include <stdexcept>    // Standard exception classes
#include <typeinfo>     // Runtime type information
#include <utility>      // Utility components (e.g., std::pair)
#include <tuple>
#include <cstdio>
#include <bitset>

using namespace std;

// ************ Setting up  ************
#define FPTU ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define BUG(x) {cerr << #x << " = " << x << endl;}
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ll  long long
#define ull unsigned long long
#define usi unsigned int
#define pll pair<ll,ll>
#define plp pair<ll,pll>
#define ppl pair<pll,ll>
#define ppp pair<pii,pii>
#define oo 1000111000
#define ooo 1000111000111000111
#define inf 0x3f //4557430888798830399
#define fi first
#define se second
#define vt vector
#define pb push_back
#define all(arr) arr.begin(),arr.end()
#define bit(n, i) (((n) >> (i)) & 1)
#define db(x) cerr << #x << " = " << (x) << '\n';

ll rand_num(ll a,ll b) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<ll> dist(a,b);
    return dist(mt);
}

int mod=1e9+7; // MODDDDDDDDDDDDD

template <typename T> void minimize(T &a, T b){ if(a>b)  a=b; }
template <typename T> void maximize(T &a, T b){ if(a<b)  a=b; }
template <typename T> void add(T &a, T b){ a+=b; if(a>=mod) a-=mod; }
template <typename T> T gcd(T a, T b){
    while(a!=0&&b!=0) if(a>b) a%=b; else b%=a; return a+b; }
void read_file()
{
    freopen("sample.inp","r",stdin);
    freopen("sample.out","w",stdout);
}
// =========> <3 VietHai1709 <3  <=========
struct line{
    ll a,b;
    line(ll x=0,ll y=ooo)
    {
        a=x; b=y;
    }
    ll get(ll x)
    {
        return a*x+b;
    }
};
struct LichaoTree{
    // get max => lower convexhull
    // get min => upper convexhull

    vt<line> F;
    LichaoTree(int n){
        F.resize(n<<2);
    }
    
    void add(int id,int l,int r,line cur)
    {
        int mid=(l+r)>>1;
        bool lef = cur.get(l) < F[id].get(l);
        bool mi = cur.get(mid) < F[id].get(mid);
        if(mi) swap(F[id],cur);
        if(l==r) return;
        if(lef==mi) add(id*2+1,mid+1,r,cur);
        else add(id*2,l,mid,cur);
    }

    ll query(int id,int l,int r,ll x)
    {
        int mid=(l+r)>>1;
        if(l==r) return F[id].get(x);
        ll ans=F[id].get(x);
        if(x<=mid) minimize(ans, query(id*2,l,mid,x));
        else minimize(ans, query(id*2+1,mid+1,r,x));
        return ans;
    }
};
void Minnnnnnn()
{
    int n,x;
    cin>>n>>x;
    vt<ll> a(n),b(n),f(n);
    for(ll &i : a) cin>>i;
    for(ll &i : b) cin>>i;
    int mx=1e6;
    LichaoTree myLichao(mx);
    myLichao.add(1, 1, mx, line(x,0));
    for(int i=0;i<n;i++){
        f[i]=myLichao.query(1, 1, mx, a[i]);
        myLichao.add(1, 1, mx, line(b[i],f[i]));
    }
    cout<<f[n-1];
}


int main(){
    
    FPTU; //fast
    
    read_file();
    
    int __=1;
    //cin>>__;
    for(int _=1;_<=__;_++)
    {
        Minnnnnnn();
    }
    cerr << "Time elapsed: " << TIME << " s.\n";

    return 0;
}
//https://cses.fi/problemset/task/2085/
