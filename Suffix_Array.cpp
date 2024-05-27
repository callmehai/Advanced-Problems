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
const int N=1e6+5;
vt<ppi> suffs;
void radix_sort(vt<ppi> &arr)
{
    for(int i=1;i<=2;i++)
    {
        auto key = [&](const ppi &x)
        {
            return i==1 ? x.fi.se:x.fi.fi;
        };
        
        int MAX=0;
        for(auto &x:arr) maximize(MAX, key(x));
        vt<int> cnt(MAX+1);
        vt<int> start(MAX+1);
        for(auto &x:arr) cnt[key(x)]++;
        for(int i=1;i<=MAX;i++) start[i]=start[i-1]+cnt[i-1];
        vt<ppi> new_arr(arr.size());
        for(auto &x:arr)
        {
            new_arr[start[key(x)]++]=x;
        }
        swap(arr,new_arr);
    }
}
int count_substr(string s,string t)
{
    int size_t=(int)t.size();
    int n=(int)s.size();
    int L=-1,R=-1;
    
    int l=1,r=(int)n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        int st=suffs[mid].se;
        //cerr<<l<<' '<<r<<' '<<mid<<' '<<st<<'\n';

        int ok=0;
        for(int i=0;i<size_t;i++)
            if(s[st+i]!=t[i])
            {
                if(s[st+i]>t[i]) ok=-1;
                else ok=1;
                break;
            }
        if(ok==0)
        {
            L=mid;
            r=mid-1;
        }
        else if(ok==-1) r=mid-1;
        else l=mid+1;
    }
    l=1; r=(int)n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        int st=suffs[mid].se;
        //cerr<<l<<' '<<r<<' '<<mid<<' '<<st<<'\n';

        int ok=0;
        for(int i=0;i<size_t;i++)
            if(s[st+i]!=t[i])
            {
                if(s[st+i]>t[i]) ok=-1;
                else ok=1;
                break;
            }
        if(ok==0)
        {
            R=mid;
            l=mid+1;
        }
        else if(ok==-1) r=mid-1;
        else l=mid+1;
    }
    
    if(L==-1) return 0;
    return R-L+1;

}
int main(){
    FPTU;

    string s;
    cin>>s;
    s+='$';
    int n=(int)s.size();
    suffs.resize(n);
    for(int i=0;i<n;i++) suffs[i]={{s[i],s[i]},i};
    sort(all(suffs));
    vt<int> ranks(n+1);
    ranks[suffs[0].se]=0;
    for(int i=1;i<n;i++)
    {
        ppi c = suffs[i];
        ppi p = suffs[i-1];
        ranks[c.se]=ranks[p.se]+(c.fi>p.fi);
    }
    for(int k=1;k<n;k*=2)
    {
        for(auto &[val,id]:suffs) val={ranks[id],ranks[(id+k)%n]};
        
        radix_sort(suffs);
        
        for(int i=1;i<n;i++)
        {
            ppi c = suffs[i];
            ppi p = suffs[i-1];
            ranks[c.se]=ranks[p.se]+(c.fi>p.fi);
        }
    }
    for(int i=1;i<n;i++) cout<<suffs[i].se<<' ';
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
//https://judge.yosupo.jp/problem/suffixarray
