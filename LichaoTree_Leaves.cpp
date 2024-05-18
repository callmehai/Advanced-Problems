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

// ************ End Setting ************
struct line{
    ll m,b;
    line(ll x=0,ll y=ooo)
    {
        m=x; b=y;
    }
    ll eval(ll x)
    {
        return m*x+b;
    }
};
const int N=1e5+5;
const int M=11;
// =========> Declaring variables <=======
ll a[N],s[N],g[N],dp[N][M];
vt<line> Line;
// =========> <3 Han Han <3  <=======
line F[4*N][M];
void add_line(int id,int k,int l,int r,line L)
{
    int mid=(l+r)/2;
    bool lef = L.eval(l) < F[id][k].eval(l);
    bool mi =L.eval(mid) < F[id][k].eval(mid);
    if(mi) swap(F[id][k],L);
    if(l==r)  return;
    if(lef==mi) add_line(id*2+1, k, mid+1, r, L);
    else add_line(id*2,k,l,mid,L);
}
ll get(int id,int k,int l,int r,ll x)
{
    if(l==r) return F[id][k].eval(x);
    int mid=(l+r)/2;
    ll ans=F[id][k].eval(x);
    if(x<=mid) minimize(ans, get(id*2,k,l,mid,x));
    else minimize(ans, get(id*2+1,k,mid+1,r,x));
    return ans;
}
int main()
{
    FPTU;
    freopen("inp.txt", "r", stdin);
    freopen("out.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        g[i]=g[i-1]+a[i]*i;
        for(int j=1;j<=k;j++) dp[i][j]=ooo;
    }
//    for(int i=1;i<=n;i++) cout<<s[i]<<' '; cout<<'\n';
//    for(int i=1;i<=n;i++) cout<<g[i]<<' '; cout<<'\n';
    dp[n][1]=0;
    for(int i=n-1;i>=1;i--)
    {
        dp[i][1]=g[n]-g[i]-i*(s[n]-s[i]);
        add_line(1, 1, 1, n, line(-s[i],dp[i+1][1]+g[i]));
        for(int p=2;p<=k;p++)
        {
            dp[i][p]= get(1,p-1,1,n,i)-g[i]+i*s[i];
            add_line(1, p, 1, n, line(-s[i],dp[i+1][p]+g[i]));
        }
    }
//    for(int p=1;p<=k;p++)
//    {
//        for(int i=1;i<=n;i++) cout<<dp[i][p]<<' ';
//        cout<<'\n';
//    }
    cout<<dp[1][k];
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
    
}


// Gitchee gitchee goo means that I love you
/* Idea:
 dp[i][k] = min(dp[j+1][k-1]+f[i][j])
 
 we have k convex-hulls,

 f[i][j] is the cost to move leafs located in i+1, i+2,..., j to i

 f[1][i] = g[i] - s[i]
 
 where g[i] = a[1]*1 + a[2]*2 +...+ a[i]*i
 and s[i] = a[1] + a[2] +...+ a[i]
 
 f[i][j] = g[j] - g[i] - i*s[j] + i*s[i]
 
 now, dp[i][k] = min(dp[j+1][k-1] + g[j] - g[i] - i*s[j] +i*s[i])
 = min(dp[j+1][k-1]+g[j] -s[j]*i) -g[i] + i*s[i]

*/



// ************ Create Tests ************

void build_test()
{
    char x[]="out000.txt";
    int num_test=30;
    for(int ii=21;ii<=num_test;ii++)
    {
        string s=to_string(ii);
        int c=5;
        int u=(int)s.size()-1;
        while(u>=0)
        {
            x[c--]=s[u--];
        }
        freopen(x, "w", stdout);
       // *** opcode here ***
        ll n,m;
        n=rand_num(100000-100,100000);
        m=rand_num(10000,n);
        cout<<n<<' '<<m;
    }
}
/* Note:
  
*/

