#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#include <cstring>
#endif

#if __cplusplus >= 202002L
#include <barrier>
#include <bit>
#include <compare>
#include <concepts>
#if __cpp_impl_coroutine
# include <coroutine>
#endif
#include <latch>
#include <numbers>
#include <span>
#include <semaphore>
#include <version>
#endif

#if __cplusplus > 202002L
#include <spanstream>
#endif
using namespace std;

// ************ Setting up  ************
#define FPTU ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define BUG(x) {cerr << #x << " = " << x << endl;}
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ll long long
#define ull unsigned long long
#define usi unsigned int
#define pll pair<ll,ll>
#define plp pair<ll,pll>
#define ppl pair<pll,ll>
#define ppp pair<pii,pii>
#define oo 1000111000
#define ooo 1000111000111000111
#define fi first
#define se second
#define pri_qu priority_queue
#define vt vector
#define pb push_back
#define all(arr) arr.begin(),arr.end()
void build_test();
random_device rd;
mt19937 mt(rd());
ll rand_num(ll a,ll b)
{
    uniform_int_distribution<ll> dist(a,b);
    return dist(mt);
}
template <typename T> void minimize(T &a, T b){ if(a>b) a=b;}
template <typename T> void maximize(T &a, T b){ if(a<b) a=b;}
template <typename T> T gcd(T a, T b)
{
    while(a!=0&&b!=0)
    {
        if(a>b) a%=b;
        else b%=a;
    }
    return a+b;
}
bool bit(ll a,int i) { return a>>i&1; }
vt<pii> wasd={{-1,0}, {0,-1}, {0,1}, {1,0}};
vt<pii> WASD={{-1,0}, {0,-1}, {0,1}, {1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
vt<pii> knight={{-1,-1},{-1,1},{1,-1},{1,1}};
vt<string> step ={"U", "L", "R", "D", "LU", "RU", "LD", "RD"};
pri_qu<pii,vector<pii>,greater<pii>> pq;

// =========> <3 VietHai1709 <3  <=======
const int N=1e5+5;
ll p,n,mod;
struct xx
{
    ll mat[2][2];
};
xx A;
ll mul_mod(ll a,ll b)
{
    if(b==0) return 0;
    if(b==1) return a%mod;
    
    ll c=mul_mod(a,b/2);
    if(b&1) return (c+c+a)%mod;
    return (c+c)%mod;
}
xx mul_mat(xx B, xx C)
{
    xx D;
    for(int i=0;i<=1;i++)
        for(int j=0;j<=1;j++) D.mat[i][j]=0;
    for(int i=0;i<=1;i++)
        for(int j=0;j<=1;j++)
            for(int k=0;k<=1;k++)
            {
                D.mat[i][j]+=mul_mod(B.mat[i][k],C.mat[k][j]);
                if(D.mat[i][j]>=mod) D.mat[i][j]-=mod;
            }
    return D;
}
xx pow_mat(xx B,ll p)
{
    if(p==1) return B;
    xx C=pow_mat(B,p/2);
    if(p&1) return mul_mat(mul_mat(C,C),B);
    return mul_mat(C,C);
}
int main(){
    FPTU;
    //build_test(); return 0;

    cin>>p>>n>>mod;
    A.mat[0][0]=p;
    A.mat[0][1]=0;
    A.mat[1][0]=A.mat[1][1]=1;
    A=pow_mat(A,n);
    cout<<(A.mat[0][0]+A.mat[1][0])%mod;
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
void build_test()
{
    char x[]="out000.txt";
    int num_test=1;
    for(int ii=1;ii<=num_test;ii++)
    {
        string s=to_string(ii);
        int c=5;
        int u=(int)s.size()-1;
        while(u>=0)
        {
            x[c--]=s[u--];
        }
        freopen(x, "w", stdout);
        
    }
}
