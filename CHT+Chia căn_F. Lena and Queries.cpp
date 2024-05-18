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
    ll m,b,id;
    
    line(ll x=0,ll y=-ooo,ll i=0)
    {
        m=x; b=y; id=i;
    }

    ll eval(ll x){
        return m*x+b;
    }
};
const int N=3e5+2;
const int M=550;
// =========> Declaring variables <=======
ll n;
vt<line> Line,CHT;
vt<pll> query;
bool in_hull[N],deleted[N];
ll a[N],b[N],type[N],x[N],xoa[N],ans[N];
// =========> <3 Han Han <3  <=======

bool cmp(line u,line v)
{
    if(u.m!= v.m) return u.m<v.m;
    return u.b<v.b;
}
bool check_the_last(line u, line v, line w)
{
    // return (u.b-v.b)*(w.m-u.m) < (v.m-u.m)*(u.b-w.b);
    return (double)(u.b-v.b)/(v.m-u.m) < (double)(u.b-w.b)/(w.m-u.m);
}
void add_line(ll m, ll b)
{
    line cur=line(m,b);
    int P=(int)CHT.size();
    while(P>=2 && !check_the_last(CHT[P-2],CHT[P-1],cur) )
    {
        CHT.pop_back();
        P--;
    }
    CHT.pb(cur);
}
void build_hull()
{
    CHT.clear();
    CHT.reserve(n);
    for(line L:Line)
    {
        if(in_hull[L.id])
        {
            add_line(L.m,L.b);
        }
    }
}
void build_query(ll l,ll r)
{
    query.clear();
    query.reserve(r-l+1);
    for(ll i=l;i<=r;i++) if(type[i]==3)
        query.pb({x[i],i});
    sort(all(query));
    int P=(int)CHT.size();
    int last=0;
    for(pll k:query)
    {
        while(last+1<P && CHT[last].eval(k.fi)<CHT[last+1].eval(k.fi))
                last++;
        if(last<P) ans[k.se]=CHT[last].eval(k.fi);
    }
}
int main()
{
    FPTU;

    cin>>n;
    memset(in_hull,0,sizeof(in_hull));
    memset(deleted,0,sizeof(deleted));

    for(ll i=1;i<=n;i++)
    {
        ans[i]=-ooo;
        cin>>type[i];
        if(type[i]==1)
        {
            cin>>a[i]>>b[i];
            Line.pb(line(a[i],b[i],i));
        }
        else if(type[i]==2)
        {
            cin>>xoa[i];
        }
        else
        {
            cin>>x[i];
        }
    }
    sort(Line.begin(),Line.end(),cmp);
    ll k=sqrt(n);
    for(ll i=1;i<=n;i+=k)
    {
        ll j=min(n,i+k);
        for(ll p=i;p<=j;p++) if(type[p]==2&&in_hull[xoa[p]]==1)
        {
            deleted[xoa[p]]=1;
            in_hull[xoa[p]]=0;
        }

        build_hull();
        build_query(i,j);

        for(ll p=i;p<=j;p++)
        {
            if(type[p]==1) in_hull[p]=1;
            else if(type[p]==2) 
            {
                in_hull[xoa[p]]=0;
                deleted[xoa[p]]=0;
            }
            else
            {
                for(ll z=i;z<p;z++)
                    if(type[z]==1&&in_hull[z]==1)
                        maximize(ans[p],a[z]*x[p]+b[z]);
                for(ll z=p+1;z<=j;z++)
                    if(type[z]==2&&deleted[xoa[z]]==1)
                        maximize(ans[p],a[xoa[z]]*x[p]+b[xoa[z]]);
            }
        }
    }
    for(ll i=1;i<=n;i++) if(type[i]==3)
    {
        if(ans[i]==-ooo) cout<<"EMPTY SET"<<'\n';
        else cout<<ans[i]<<'\n';
    }
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
    int num_test=100;
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

