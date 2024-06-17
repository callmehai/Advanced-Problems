//13-12-2019 <3
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
#define inf 4557430888798830399
#define fi first
#define se second
#define pri_qu priority_queue
#define vt vector
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define bitmin(n) __builtin_ctzll(n)
#define bitmax(n) 31-__builtin_clz(n)
#define bitmaxll(n) 63-__builtin_clz(n)
#define db(x) cerr << #x << " = " << (x) << '\n';
random_device rd;
mt19937 mt(rd());
ll rand_num(ll a,ll b) {uniform_int_distribution<ll> dist(a,b);return dist(mt);}

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
vt<pii> wasd={{-1,0}, {0,-1}, {0,1}, {1,0}};
vt<pii> WASD={{-1,0}, {0,-1}, {0,1}, {1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
vt<pii> knight={{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};
vt<string> step ={"U", "L", "R", "D", "LU", "RU", "LD", "RD"};


struct DSU {
    int n;
    vector<int> pa;
    DSU(int _n) {
        n = _n;
        pa.assign(n, 0);
        iota(pa.begin(), pa.end(), 0);
    }
    int timcha(int u) {
        return pa[u] == u ? u : pa[u] = timcha(pa[u]);
    }
    bool merge(int u, int v) {
        u = timcha(u); v = timcha(v);
        if (u == v) return 0;
        pa[v] = u;
        return 1;
    }
};
long long MST(vector<pair<int,pair<int,int>>> &e,int n) { // return MST and its total cost
    sort(e.begin(),e.end());
    vector<pair<int,pair<int,int>>> ans;
    long long res = 0;
    DSU dsu(n);
    for (auto edge: e) {
        int u = edge.second.first, v = edge.second.second, p = edge.first;
        if (dsu.merge(u, v)) {
            ans.push_back(edge);
            res += p;
        }
    }
    e = ans;
    return res;
}
long long poww(long long a,ll b, long long M)
{
    if(b==0) return 1;
    if(b==1) return a%M;
    ll p=poww(a,b/2,M);
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
    Matrix operator ^(long long M) {
        // Check square matrix
        assert(x == y);

        Matrix base = (*this);
        Matrix ans  = Identity_Matrix(x);
        for (; M > 0; M >>= 1, base = base * base)
            if (M & 1) ans = ans * base;
        return ans;
    }
};
void read_file()
{
    freopen("sample.inp","r",stdin);
    freopen("sample.out","w",stdout);
}
// =========> <3 VietHai1709 <3  <=======

void Missing_Min()
{
    
}
int main(){
    FPTU; read_file();
    int Test_case=1;
    cin>>Test_case;
    while(Test_case--)
    {
        Missing_Min();
    }
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
