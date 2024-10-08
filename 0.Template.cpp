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
template <typename T> T gcd(T a, T b)
{
    while(a!=0&&b!=0)
    {
        if(a>b) a%=b;
        else b%=a;
    }
    return a+b;
}
vector<pair<int,int>> queen  = {{-1,0},{0,-1},{0,1},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
vector<pair<int,int>> knight = {{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
vector<pair<int,int>> bishop = {{-1,-1},{-1,1},{1,-1},{1,1}};
vector<pair<int,int>> rook   = {{-1,0},{0,-1},{0,1},{1,0}};
long long poww(long long a,long long b, long long M)
{
    if(b==0) return 1;
    if(b==1) return a%M;
    long long p=poww(a,b/2,M);
    if(b&1) return p*p%M*a%M;
    return p*p%M;
}
long long mull(long long a,long long b,long long M) // if a*b > 1e18
{
    if(b==0) return 0;
    if(b==1) return a%M;
    
    long long c=mull(a,b/2,M);
    if(b&1) return (+c+a)%M;
    return (c+c)%M;
}
int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            res -= res / i;
        }
    }
    if (n != 1) {
        res -= res / n;
    }
    return res;
}
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
struct ConvextHullTrick{
    int n;
    int flag;
    vt<line> Line;
    ConvextHullTrick(){
        n=0;
        flag=0;
        Line.clear();
    }
    bool bad(line u,line v,line w)
    {
        return (double)(u.b-w.b)/(w.a-u.a)<=(double)(u.b-v.b)/(v.a-u.a);
        //return (u.b-w.b)*(v.m-u.m)<=(u.b-v.b)*(w.m-u.m);
    }
    void add(line L)
    {
        while(n>=2 && bad(Line[n-2],Line[n-1],L))
        {
            Line.pop_back();
            n--;
        }
        Line.pb(L);
        n++;
    }
    ll query(ll x)
    {
        if(flag>n-1) flag=n-1;
        while(flag+1<n && Line[flag].get(x)>Line[flag+1].get(x)) flag++;
        return Line[flag].get(x);
    }
};
struct LichaoTree{
    // get max => lower convexhull
    // get min => upper convexhull

    vt<line> F;
    int n;
    LichaoTree(int _){
        n=_;
        F.resize(n<<2);
    }
    void reset(){
        F.clear();
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
struct EulerTour{
    int n;
    vt<int> A;
    vt<int> end;
    vt<int> pos;
    vt<vt<int>> nxt;
    int flag=0;
    EulerTour(int _){
        n=_;
        A.resize(n+1);
        end.resize(n+1);
        pos.resize(n+1);
        nxt.resize(n+1);
    }
    void build(int u){
        pos[u]=++flag;
        A[flag]=u;
        for(int v : nxt[u]){
            build(v);
        }
        end[u]=flag;
    }
};
struct DSU {
    int n;
    int cnt;
    vector<int> pa;
    DSU(int _n) {
        n = _n;
        cnt=n;
        pa.resize(n+1,-1);
    }
    int root(int u) {
        return pa[u] < 0 ? u : pa[u] = root(pa[u]);
    }
    int group_count(){
        return cnt;
    }
    int count(int u){
        return -pa[root(u)];
    }
    bool share(int u,int v){
        return root(u) == root(v);
    }
    bool merge(int u, int v) {
        u = root(u); v = root(v);
        if (u == v) return 0;
        if(pa[u] > pa[v]) swap(u,v);
        pa[u]+=pa[v]; pa[v]=u;
        cnt--;
        return 1;
    }
};
//long long MST(vector<pair<int,pair<int,int>>> &e,int n) { // return MST and its total cost
//    sort(e.begin(),e.end());
//    vector<pair<int,pair<int,int>>> ans;
//    long long res = 0;
//    DSU dsu(n);
//    for (auto edge: e) {
//        int u = edge.second.first, v = edge.second.second, p = edge.first;
//        if (dsu.merge(u, v)) {
//            ans.push_back(edge);
//            res += p;
//        }
//    }
//    e = ans;
//    return res;
//}
void Dijktra(int st,vt<vt<int>> Edge, vt<int> &dis)
{
    dis[st]=0;
    priority_queue<pii,vt<pii>,greater<pii>> pq;
    pq.push({0,st});
    while(!pq.empty())
    {
        pii k=pq.top(); pq.pop();
        int u = k.se, w = k.fi;
        
        if (w > dis[u]) continue;

        for(auto &v: Edge[u]) {
           if (dis[v] > w + 1) {
               dis[v] = 1 + w;
               pq.push({dis[v], v});
           }
        }
    }
}
// 2SAT 
int notP(int u){
    if(u<=n) return u+n;
    return u-n;
}

struct Tajan{
    int n,cnt,timeDFS;
    vt<int> num,low,id,st;
    vt<vt<int>> ke;

    Tajan(int _){
        n=_;
        cnt=0;
        timeDFS=0;
        num.resize(n+1);
        low.resize(n+1);
        id.resize(n+1,0);
        st.resize(n+1);
        ke.resize(n+1);
        for(int i=1;i<=n;i++) ke[i].clear();
    }
    void dfs(int u){
        num[u] = low[u] = ++timeDFS;
        st[++st[0]]=u;
        for(int &v : ke[u]){
            if(id[v]) continue;
            if(num[v]==0){
                dfs(v);
                low[u]=min(low[u],low[v]);
            }
            else{
                low[u]=min(low[u],num[v]);
            }
        }
        
        if(num[u]==low[u]){
            cnt++;
            while(true){
                int v = st[st[0]--];
                id[v]=cnt;
                if(v==u) break;
            }
        }
        
    }
    void build(){
        for(int i=1;i<=n;i++) if(!id[i]){
            dfs(i);
        }
    }
};
struct Matrix{
    int x,y;
    vt<vt<int>> a;
    Matrix(int _x,int _y)
    {
        x=(int)_x;
        y=(int)_y;
        a.resize(x,vt<int>(y,0));
    }
    Matrix Identity_Matrix(int n)
    {
        Matrix I = Matrix(n, n);
        while (n--) I.a[n][n] = 1;
        return I;
    }
    Matrix operator *(const Matrix& other) { //[x,y] * [y,z] = [x,z]
        // Check if can multiply
        assert(y == other.x);
        int z= other.y;
        Matrix product(x,z);
        for(int i = 0; i <x; ++i) {
            for(int j = 0; j < z; ++j) {
                for(int k = 0; k < y; ++k) {
                    product.a[i][j] = (product.a[i][j] + 1LL * a[i][k] * other.a[k][j] % mod ) % mod;
                }
            }
        }
        return product;
    }
    void operator *=(const Matrix& other) { //[x,y] * [y,z] = [x,z]
        // Check if can multiply
        assert(y == other.x);
        int z= other.y;
        Matrix product(x,z);
        for(int i = 0; i <x; ++i) {
            for(int j = 0; j < z; ++j) {
                for(int k = 0; k < y; ++k) {
                    product.a[i][j] = (product.a[i][j] + 1LL * a[i][k] * other.a[k][j] % mod ) % mod;
                }
            }
        }
        *this = product;
    }
    Matrix operator ^(long long M) {
        // Check square matrix
        assert(x == y);

        Matrix base = (*this);
        Matrix ans  = Identity_Matrix(x);
        for (; M > 0; M >>= 1, base = base * base)
            if (M & 1) ans = ans * base;
        return ans;
    }
    void operator ^=(long long M) {
        // Check square matrix
        assert(x == y);

        Matrix base = (*this);
        Matrix ans  = Identity_Matrix(x);
        for (; M > 0; M >>= 1, base = base * base)
            if (M & 1) ans = ans * base;
        *this = ans;
    }
};
struct RealMatrix{
    int x,y;
    vt<vt<double>> a;
    RealMatrix(int _x,int _y)
    {
        x=(int)_x;
        y=(int)_y;
        a.resize(x,vt<double>(y,0));
    }
    RealMatrix Identity_RealMatrix(int n)
    {
        RealMatrix I = RealMatrix(n, n);
        while (n--) I.a[n][n] = 1;
        return I;
    }
    RealMatrix operator *(const RealMatrix& other) { //[x,y] * [y,z] = [x,z]
        // Check if can multiply
        assert(y == other.x);
        int z= other.y;
        RealMatrix product(x,z);
        for(int i = 0; i <x; ++i) {
            for(int j = 0; j < z; ++j) {
                for(int k = 0; k < y; ++k) {
                    product.a[i][j] = (product.a[i][j] + a[i][k] * other.a[k][j]  ) ;
                }
            }
        }
        return product;
    }
    void operator *=(const RealMatrix& other) { //[x,y] * [y,z] = [x,z]
        // Check if can multiply
        assert(y == other.x);
        int z= other.y;
        RealMatrix product(x,z);
        for(int i = 0; i <x; ++i) {
            for(int j = 0; j < z; ++j) {
                for(int k = 0; k < y; ++k) {
                    product.a[i][j] = (product.a[i][j] +  a[i][k] * other.a[k][j]  );
                }
            }
        }
        *this = product;
    }
    RealMatrix operator ^(long long M) {
        // Check square matrix
        assert(x == y);

        RealMatrix base = (*this);
        RealMatrix ans  = Identity_RealMatrix(x);
        for (; M > 0; M >>= 1, base = base * base)
            if (M & 1) ans = ans * base;
        return ans;
    }
    void operator ^=(long long M) {
        // Check square matrix
        assert(x == y);

        RealMatrix base = (*this);
        RealMatrix ans  = Identity_RealMatrix(x);
        for (; M > 0; M >>= 1, base = base * base)
            if (M & 1) ans = ans * base;
        *this = ans;
    }
};
struct BIT{ // getmax
    vt<int> A;
    int n;
    BIT(int _){
        n=_;
        A.resize(n+1,0);
    }
    void up(int x,int val)
    {
        for(int i=x;i<=n;i+=(i&(-i))){
            maximize(A[i],val);
        }
    }
    int get(int x){
        int ans=0;
        for(int i=x;i>0;i-=(i&(-i))){
            maximize(ans,A[i]);
        }
        return ans;
    }
};

struct SegmentTree{ // divided by 3
    struct node{
        int ze=0,one=0,two=0;

        node operator +(node other) {
            node ans=*this;
            ans.ze+=other.ze;
            ans.one+=other.one;
            ans.two+=other.two;
            return ans;
        }
    };
    vt<node> A;
    vt<int> a,lazi;
    int n;
    SegmentTree(int _){
        n=_;
        A.resize(4*n+1);
        lazi.resize(4*n+1,0);
        a.resize(n+1);
    }
    void build(int id,int l,int r)
    {
        if(l==r)
        {
            if(a[l]==0) A[id].ze=1;
            else if(a[l]==1) A[id].one=1;
            else A[id].two=1;
            return;
        }
        int mid=(l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        A[id]=A[id*2]+A[id*2+1];
    }
    void down(int id)
    {
        int val=lazi[id]%3;
        lazi[id]=0;
        lazi[id*2]+=val;
        lazi[id*2+1]+=val;
        id*=2;
        for(int i=1;i<=val;i++)
        {
            swap(A[id].ze,A[id].one);
            swap(A[id].ze,A[id].two);
            
            swap(A[id+1].ze,A[id+1].one);
            swap(A[id+1].ze,A[id+1].two);
        }
    }
    void up(int id,int l,int r,int u,int v)
    {
        if(l>v||r<u) return;
        if(l>=u&&r<=v)
        {
            lazi[id]++;
            swap(A[id].ze,A[id].one);
            swap(A[id].ze,A[id].two);
            return;
        }
        int mid=(l+r)/2;
        down(id);
        up(id*2,l,mid,u,v);
        up(id*2+1,mid+1,r,u,v);
        A[id].ze=A[id*2].ze+A[id*2+1].ze;
        A[id].one=A[id*2].one+A[id*2+1].one;
        A[id].two=A[id*2].two+A[id*2+1].two;
    }
    node get(int id,int l,int r,int u,int v)
    {
        if(l>v||r<u) return {0,0,0};
        if(l>=u&&r<=v)
        {
            return A[id];
        }
        int mid=(l+r)/2;
        down(id);
        return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
        
    }
};

void read_file()
{
    freopen("sample.inp","r",stdin);
    freopen("sample.out","w",stdout);
}
// =========> <3 VietHai1709 <3  <=========

void Minnnnnnn()
{

}
int main(){
    FPTU; read_file();
    int Test_case=1;
    //cin>>Test_case;
    while(Test_case--)
    {
        Minnnnnnn();
    }
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}


