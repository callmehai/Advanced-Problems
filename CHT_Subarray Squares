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
const int M=3001;
// =========> Declaring variables <=======

// =========> <3 Han Han <3  <=======
ll s[N],last[M];
vt<line> Line[M];
bool bad(line u,line v,line w)
{
    return (double)(u.b-w.b)/(w.m-u.m)<=(double)(u.b-v.b)/(v.m-u.m);
    //return (u.b-w.b)*(v.m-u.m)<=(u.b-v.b)*(w.m-u.m);
}
void add_line(int k,line L)
{
    while(Line[k].size()>=2 && bad(Line[k][Line[k].size()-2],Line[k][Line[k].size()-1],L))
    {
        Line[k].pop_back();
    }
    Line[k].pb(L);
}
ll query(int k,ll x)
{
    int P=(int)Line[k].size();
    if(last[k]>P-1) last[k]=P-1;
    while(last[k]<P-1 && Line[k][last[k]].eval(x)>Line[k][last[k]+1].eval(x)) last[k]++;
    return Line[k][last[k]].eval(x);
}
int main()
{
    FPTU;
//    freopen("inp.txt", "r", stdin);
//    freopen("out.txt","w",stdout);
    memset(last,0,sizeof(last));
    int n,k;
    cin>>n>>k;
    s[0]=0;
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        s[i]=s[i-1]+x;
    }
    ll ans=0;
    add_line(0,line(0,0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=min(i,k);j++)
        {
            ans=query(j-1,s[i])+s[i]*s[i];
            add_line(j,line(-2*s[i],ans+s[i]*s[i]));
        }

    cout<<ans;
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
    
}


// Gitchee gitchee goo means that I love you
/* Idea:

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


