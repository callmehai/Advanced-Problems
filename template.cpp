//13/12/2019 - 08/05/2022
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <cassert>
#include <list>
#include <tuple>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstdio>
#include <random>
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
#define mp make_pair
#define all(arr) arr.begin(),arr.end()
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define bitmin(n) __builtin_ctzll(n)
#define bitmax(n) 31-__builtin_clz(n)
#define bitmaxll(n) 63-__builtin_clzll(n)
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


