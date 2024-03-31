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
const int N=1e6+5;
const int M=11;
// =========> Declaring variables <=======
ll n,a,b,c,sum[N],x[N],dp[N],last_line=0;
vt<line> Line;
// =========> <3 Han Han <3  <=======

bool check_the_last(line u, line v, line w)
{
    // intersection of  (u,w) must be greater than that of (u,v)
    // else, line v must be deleted
    // <=> (u.b-v.b)/(v.m-u.m) < (u.b-w.b)/(w.m-u.m)
    // <=> (u.b-v.b)*(w.m-u.m) < (v.m-u.m)*(u.b-w.b)
    // return (u.b-v.b)*(w.m-u.m) < (v.m-u.m)*(u.b-w.b);
    // ** this may exceed long long **
    return (double)(u.b-v.b)/(v.m-u.m) < (double)(u.b-w.b)/(w.m-u.m);
}
void add_line(ll m, ll b)
{
    line cur={m,b};
    int P=(int)Line.size();
    while(P>=2 && !check_the_last(Line[P-2],Line[P-1],cur) )
    {
        Line.pop_back();
        P--;
    }
    Line.pb(cur);
}
ll val(ll x, line u)
{
    return u.m*x+u.b;
}
ll query(ll x)
{
    int P=(int)(Line.size());
    if(last_line >= P) last_line=P-1;
    while(last_line+1<P && val(x,Line[last_line]) < val(x, Line[last_line+1]) )
        last_line++;
    return val(x,Line[last_line]);
}
int main()
{
    FPTU;

    cin>>n>>a>>b>>c;
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
        sum[i]=sum[i-1]+x[i];
    }
    dp[1]= a*x[1]*x[1]+b*x[1]+c;
    add_line(-2*a*x[1], a*x[1]*x[1]-b*x[1]+dp[1]);
    for(int i=2;i<=n;i++)
    {
        dp[i]= a*sum[i]*sum[i]+b*sum[i]+c;
        maximizell(dp[i], query(sum[i]) + a*sum[i]*sum[i]+b*sum[i]+c);
        add_line(-2*a*sum[i], a*sum[i]*sum[i]-b*sum[i]+dp[i]);
    }
    cout<<dp[n];
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
    
}
// Gitchee gitchee goo means that I love you
/*
dp[n] = dp[k] + a*(sum[n]-sum[k])^2 + b*(sum[n]-sum[k]) + c
     = dp[k] + a*sum[n]^2 + a*sum[k]^2 - 2*a*sum[n]*sum[k] + b*sum[n] - b*sum[k] + c
     = (-2*a*sum[k]) * sum[n] + (a*sum[k]^2-b*sum[k]+dp[k]) + (a*sum[n]^2+b*sum[n]+c)
     = max(m * sum[n] + z ) + p
*/


