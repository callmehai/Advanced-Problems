//https://oj.vnoi.info/problem/euler_b
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
#define oo 1000111000
#define ooo 1000111000111000111
#define fi first
#define se second
#define pri_qu priority_queue
#define vt vector
#define pb push_back
#define all(arr) arr.begin(),arr.end()
void build_test();
template <typename T> void minimize(T &a, T b){ if(a>b) a=b;}
template <typename T> void maximize(T &a, T b){ if(a<b) a=b;}
bool bit(ll a,int i) { return a>>i&1; }
vt<pii> wasd={{-1,0}, {0,-1}, {0,1}, {1,0}};
vt<pii> WASD={{-1,0}, {0,-1}, {0,1}, {1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
vt<pii> knight={{-1,-1},{-1,1},{1,-1},{1,1}};
vt<string> step ={"U", "L", "R", "D", "LU", "RU", "LD", "RD"};
pri_qu<plp,vector<plp>,greater<plp>> pq;

random_device rd;
mt19937 mt(rd());
ll rand_num(ll a,ll b)
{
    uniform_int_distribution<ll> dist(a,b);
    return dist(mt);
}
// =========> <3 VietHai1709 <3  <=======
const int N=3e5+5;
vt<vt<int>>ke;
ll f[4*N];
ll lazi[4*N];
int n,m;
int pa[N],child[N],pos[N],head[N],chain[N],heavy[N],arr[N],en[N];
ll sum[N],a[N];
int cur=0, cur_chain=1;
void dfs(int u,int p)
{
    child[u]=1;
    int mx=0;
    for(int v:ke[u]) if(v!=p)
    {
        pa[v]=u;
        sum[v]=sum[u]+a[v];
        dfs(v,u);
        child[u]+=child[v];
        if(mx==0||child[v]>child[mx]) mx=v;
    }
    heavy[u]=mx;
}
void hld(int u)
{
    pos[u]=++cur;
    arr[cur]=u;
    chain[u]=cur_chain;
    if(head[cur_chain]==0) head[cur_chain]=u;
    if(heavy[u]!=0) hld(heavy[u]);
    for(int v:ke[u]) if(v!=pa[u] && v!=heavy[u])
    {
        ++cur_chain;
        hld(v);
    }
    en[u]=cur;
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        f[id]=sum[arr[l]];
        lazi[id]=0;
        return;
    }
    int mid=(l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    lazi[id]=0;
}
void downs(int id)
{
    ll x=lazi[id];
    lazi[id]=0;
    f[id*2]+=x;
    lazi[id*2]+=x;
    f[id*2+1]+=x;
    lazi[id*2+1]+=x;
    
}
void ups(int id,int l,int r,int u,int v,ll x)
{
    if(l>v||r<u) return;
    if(l>=u&&r<=v)
    {
        f[id]+=x;
        lazi[id]+=x;
        return;
    }
    int mid=(l+r)>>1;
    downs(id);
    ups(id*2,l,mid,u,v,x);
    ups(id*2+1,mid+1,r,u,v,x);
    f[id]=f[id*2]+f[id*2+1];
}

ll gets(int id,int l,int r,int u)
{
    if(l==r) return f[id];
    int mid=(l+r)>>1;
    downs(id);
    if(u<=mid) return gets(id*2,l,mid,u);
    return gets(id*2+1,mid+1,r,u);
}
int main(){
    FPTU;
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>n>>m;
    memset(head,0,sizeof(head));
    for(int i=1;i<=n;i++) cin>>a[i];
    ke.resize(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    pa[1]=1;
    sum[1]=a[1];
    dfs(1,0);
    hld(1);
    build(1,1,n);
    while(m--)
    {
        int k,u;
        cin>>k>>u;
        if(k==1)
        {
            ll x;
            cin>>x;
            ups(1,1,n,pos[u],en[u],x-a[u]);
            a[u]=x;
        }
        else cout<<gets(1,1,n,pos[u])<<'\n';
    }
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
/*
*******************************************************************
*                                             _|                  *
*  _|        _|   _|_|    _|                _|_|_|                *
*   _|      _|    _| _|   _|          _|_|_|_|_|_|_|_|_|          *
*   _|      _|    _|  _|  _|            _|_|_|_|_|_|_|            *
*    _|    _|     _|   _| _|              _|_|_|_|_|              *
*     _|  _|      _|    _|_|            _|_|_|  _|_|_|            *
*       _|        _|      _|          _|_|_|      _|_|_|          *
*******************************************************************
*                                                                 *
* _|      _|   _|   _|_|_|   _|_|_|_|   _|    _|     _|_|     _|  *
* _|      _|   _|   _|          _|      _|    _|   _|    _|   _|  *
*  _|    _|    _|   _|_|_|      _|      _|_|_|_|   _|_|_|_|   _|  *
*   _|  _|     _|   _|          _|      _|    _|   _|    _|   _|  *
*     _|       _|   _|_|_|      _|      _|    _|   _|    _|   _|  *
*                                                                 *
*******************************************************************/
