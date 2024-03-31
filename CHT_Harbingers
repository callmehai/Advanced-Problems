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
// ************ Create Tests ************
void sinhtest()
{
    char x[]="out000.txt";
    int num_test=100;
    srand(time(NULL));
    for(int ii=1;ii<=num_test;ii++)
    {
        string s=to_string(ii);
        int k=5;
        int u=(int)s.size()-1;
        while(u>=0)
        {
            x[k--]=s[u--];
        }
        freopen(x, "w", stdout);
        
    }
}
 /*Note:
  
  */

// ************ Setting up  ************
#define FPTU ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)

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
void minimize(int &a,int b){if(a>b) a=b;}
void maximize(int &a,int b){if(a<b) a=b;}
void minimizell(ll &a,ll b){if(a>b) a=b;}
void maximizell(ll &a,ll b){if(a<b) a=b;}
vt<pii> wasd={{-1,0}, {0,-1}, {0,1}, {1,0}};
vt<pii> WASD={{-1,0}, {0,-1}, {0,1}, {1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
vt<pii> knight={{-1,-1},{-1,1},{1,-1},{1,1}};
vt<string> step ={"U", "L", "R", "D", "LU", "RU", "LD", "RD"};
pri_qu<plp,vector<plp>,greater<plp>> pq;
struct line{ll m,b;};
struct event{ll id,cnt; line L;};
const int N=1e5+5;
const int M=11;

// =========> Declaring variables <=======
ll n,c[N],v[N],h[N],dp[N],cnt_line=0;
line Line[N];
vt<vt<pll>> ke;
vt<event> undo;
// =========> <3 Han Han <3  <=======

bool check_the_last(line u, line v, line w)
{
    // intersection of (u,v) must be lower than (u,w)'s one
    // else, line v must be deleted
    // <=> (u.b-v.b)/(v.m-u.m) < (u.b-w.b)/(w.m-u.m)
    // <=> (u.b-v.b)*(w.m-u.m) < (v.m-u.m)*(u.b-w.b)
    // return (u.b-v.b)*(w.m-u.m) < (v.m-u.m)*(u.b-w.b);
    // this may be over long long
    return (double)(u.b-v.b)/(v.m-u.m) < (double)(u.b-w.b)/(w.m-u.m);
}
void add_line(ll m, ll b)
{
    line cur={m,b};
    ll l=1, r=cnt_line-1,place=cnt_line;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(!check_the_last(Line[mid-1], Line[mid], cur))
        {
            r=mid-1;
            place=mid;
        }
        else l=mid+1;
    }
    undo.pb({place,cnt_line,Line[place]});
    Line[place]=cur;
    cnt_line=place+1;
}
ll val(ll x, line u)
{
    return u.m*x+u.b;
}
ll query(ll x)
{
    ll l=0, r=cnt_line-1;
    ll ans=val(x,Line[0]);
    while(l<r)
    {
        ll mid=(l+r)/2;
        ll u=val(x,Line[mid]);
        ll v=val(x,Line[mid+1]);
        if(u>v) l=mid+1;
        else r=mid;
        minimizell(ans, u);
        minimizell(ans, v);
    }
    return ans;
}
void roll_back()
{
    event e=undo.back(); undo.pop_back();
    Line[e.id]=e.L;
    cnt_line=e.cnt;
}
void dfs(ll u,ll pa)
{
    if(u!=1) dp[u]=query(v[u])+h[u]*v[u]+c[u];

    add_line(-h[u], dp[u]);
    for(pll ii: ke[u]) if(ii.fi!=pa)
    {
        ll v=ii.fi;
        ll w=ii.se;
        h[v]=h[u]+w;
        dfs(v,u);
    }
    roll_back();
}
int main()
{
    FPTU;

    cin>>n;
    ke.resize(n+1);
    for(int i=1;i<n;i++)
    {
        ll u,v,c;
        cin>>u>>v>>c;
        ke[u].pb({v,c});
        ke[v].pb({u,c});
    }
    for(int i=2;i<=n;i++) cin>>c[i]>>v[i];
    h[1]=0;
    dfs(1,0);
    for(int i=2;i<=n;i++) cout<<dp[i]<<' ';
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
    
}
// Gitchee gitchee goo means that I love you
/*
dp[n] = min ( dp[k] + (h[n]-h[k])*v[n] + c[n])
      = min ( dp[k] - h[k]*v[n] + h[n]*v[n]+c[n] )
      = min ( b - m*x + c) => add(-h[k],dp[k]) , query(v[n])
*/

