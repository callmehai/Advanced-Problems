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
void build_test()
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
       // *** opcode here ***

        
    }
}
/* Note:
  
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
template <typename T> void minimize(T &a, T b){ if(a>b) a=b;}
template <typename T> void maximize(T &a, T b){ if(a<b) a=b;}
vt<pii> wasd={{-1,0}, {0,-1}, {0,1}, {1,0}};
vt<pii> WASD={{-1,0}, {0,-1}, {0,1}, {1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
vt<pii> knight={{-1,-1},{-1,1},{1,-1},{1,1}};
vt<string> step ={"U", "L", "R", "D", "LU", "RU", "LD", "RD"};
pri_qu<plp,vector<plp>,greater<plp>> pq;
struct line{
    ll m,b;
    line(ll x=0,ll y=0)
    {
        m=x; b=y;
    }
    ll eval(ll x)
    {
        return m*x+b;
    }
};
const int N=1e6+5;
const int M=11;

// =========> Declaring variables <=======
int n;
line F[4*N];
bool vis[4*N];
// =========> <3 Han Han <3  <=======
void add_line(int id,int l,int r,line L)
{
    if(!vis[id])
    {
        vis[id]=1;
        F[id]=L;
        return;
    }
    if(F[id].eval(l)>L.eval(l) && F[id].eval(r)>L.eval(r)) return;
    if(F[id].eval(l)<L.eval(l) && F[id].eval(r)<L.eval(r))
    {
        F[id]=L;
        return;
    }
    int mid=(l+r)>>1;
    if(F[id].eval(l)<L.eval(l)) swap(F[id],L);
    if(F[id].eval(mid) > L.eval(mid)) add_line(id*2+1,mid+1,r,L);
    else
    {
        swap(F[id],L);
        add_line(id*2,l,mid,L);
    }
}
ll get(int id,int l,int r,ll x)
{
    if(l==r) return F[id].eval(x);
    int mid=(l+r)>>1;
    ll ans=F[id].eval(x);
    if(x<=mid) maximize(ans, get(id*2,l,mid,x));
    else maximize(ans, get(id*2+1,mid+1,r,x));
    return ans;
}
int main()
{
    FPTU;

    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int tp;
        cin>>tp;
        if(tp==1)
        {
            ll m,b;
            cin>>m>>b;
            add_line(1,1,N,line(m,b));
        }
        else
        {
            ll x;
            cin>>x;
            cout<<get(1,1,N,x)<<'\n';
        }
    }
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
// Gitchee gitchee goo means that I love you
/* Idea:

*/

