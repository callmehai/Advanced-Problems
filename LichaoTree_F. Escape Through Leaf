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
    ll m,b;
    line* lc=NULL;
    line* rc=NULL;
    
    line(ll x=0,ll y=ooo)
    {
        m=x; b=y;
    }
    ll eval(ll x){
        return m*x+b;
    }
};
const int N=3e5+2;

// =========> Declaring variables <=======
int n,child[N],big[N];
ll a[N],b[N],ans[N];
line* Line[N];
vt<vt<int>> ke;
bool is_leaf[N];
// =========> <3 Han Han <3  <=======
void add_line(int l,int r,line* cur, line* L)
{
    int mid=(l+r)/2;

    bool lef = L->eval(l) < cur->eval(l);
    bool mi  = L->eval(mid) < cur->eval(mid);
    
    if(mi) {
        swap(cur->m,L->m);
        swap(cur->b,L->b);
    }
    if(l==r) return;
    if(lef == mi )
    {
        if(cur->rc==NULL)
        {
            cur->rc=new(line);
            cur=cur->rc;
            cur->b=L->b;
            cur->m=L->m;
        }
        else add_line(mid+1,r,cur->rc,L);
    }
    else
    {
        if(cur->lc==NULL)
        {
            cur->lc=new(line);
            cur=cur->lc;
            cur->b=L->b;
            cur->m=L->m;
        }
        else add_line(l,mid,cur->lc,L);
    }
}
ll get(int l,int r,line* cur, ll x)
{
    if(l==r) return cur->eval(x);
    ll ans=cur->eval(x);
    int mid=(l+r)/2;
    if(x<=mid)
    {
        if(cur->lc!=NULL)
            minimize(ans, get(l,mid,cur->lc,x));
    }
    else
    {
        if(cur->rc!=NULL)
            minimize(ans, get(mid+1,r,cur->rc,x));
    }
    return ans;
}
void merge(line* cur, line* p)
{
    add_line(-N,N,cur,p);
    if(p->lc!=NULL) merge(cur, p->lc);
    if(p->rc!=NULL) merge(cur, p->rc);
}
void dfs(int u,int p)
{
    child[u]=1;
    big[u]=0;
    for(int v:ke[u]) if(v!=p)
    {
        dfs(v,u);
        child[u]+=child[v];
        if(child[v] > child[big[u]]) big[u]=v;
    }
    if(child[u]==1) is_leaf[u]=1;
}
line* NEW=new(line);

void dfs2(int u,int p)
{
    if(is_leaf[u])
    {
        ans[u]=0;
        NEW->b=0;
        NEW->m=b[u];
        add_line(-N,N,Line[u],NEW);
        return;
    }
    dfs2(big[u],u);
    Line[u]=Line[big[u]];
    for(int v:ke[u]) if(v!=p&&v!=big[u])
    {
        dfs2(v,u);
        merge(Line[u],Line[v]);
    }

    ans[u]=get(-N,N,Line[u],a[u]);
    NEW->b=ans[u];
    NEW->m=b[u];
    add_line(-N,N,Line[u],NEW);
}

int main()
{
    FPTU;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    ke.resize(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        ke[u].pb(v);
        ke[v].pb(u);
    }
    memset(is_leaf,0,sizeof(is_leaf));
    child[0]=0;
    dfs(1,0);
    for(int i=1;i<=n;i++) Line[i]=new(line);
    dfs2(1,0);

    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
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

