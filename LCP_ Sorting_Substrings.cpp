#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <cassert>
#include <list>
#include <tuple>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstdio>
#include <random>
using namespace std;

// ************ Setting up  ************
#define FPTU ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define BUG(x) {cerr << #x << " = " << x << endl;}
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ll   long long
#define ull unsigned long long
#define usi unsigned int
#define i128 __int128_t
#define ui128 __uint128_t
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
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define db(x) cerr << #x << " = " << (x) << '\n';

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
template <typename T> T lcm(T a, T b) {return a / gcd(a, b) * b;}

vt<pii> wasd={{-1,0}, {0,-1}, {0,1}, {1,0}};
vt<pii> WASD={{-1,0}, {0,-1}, {0,1}, {1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
vt<pii> knight={{-1,-1},{-1,1},{1,-1},{1,1}};
vt<string> step ={"U", "L", "R", "D", "LU", "RU", "LD", "RD"};
pri_qu<pii,vector<pii>,greater<pii>> pq;

// =========> <3 VietHai1709 <3  <=======
vt<ppi> suffs;
vt<int> idx_suffs;
void radix_sort(vt<ppi> &arr)
{
    for(int j=0;j<=1;j++)
    {
        auto key = [&](const ppi x)
        {
            return j==1 ? x.fi.fi : x.fi.se;
        };
        
        int MAX=0;
        for(auto x:arr) maximize(MAX,key(x));
        vt<int> cnt(MAX+1);
        vt<int> start(MAX+1);
        for(auto x:arr) cnt[key(x)]++;
        for(int i=1;i<=MAX;i++) start[i]=start[i-1]+cnt[i-1];
        vt<ppi> new_arr(arr.size());
        for(auto x:arr)
            new_arr[start[key(x)]++]=x;
        swap(arr,new_arr);
    }
}

string s;
int rmq[400005][21];
int get_min_suff(int L, int R) {
    int len = R - L + 1;
    int k = 31 - __builtin_clz(len);
    return min(rmq[L][k], rmq[R-(1<<k)+1][k]);
}
int get_lcp(int i, int j) {
    if (i == j) return (int)s.size() - i;
    if (idx_suffs[i] > idx_suffs[j]) swap(i, j);
    return get_min_suff(idx_suffs[i], idx_suffs[j]-1);
}
bool cmp(pii u,pii v)
{
    if(u.fi==v.fi) return u.se<v.se;
    int len_u=u.se-u.fi+1;
    int len_v=v.se-v.fi+1;
    int z=get_lcp(u.fi,v.fi);
    if(z<min(len_u,len_v)) return s[u.fi+z]<s[v.fi+z];
    if(len_u!=len_v) return len_u<len_v;
    return u.fi<v.fi;
    
}
int main(){
    FPTU;
    cin>>s;
    s+=' ';
    ll n=(ll)s.size();
    suffs.resize(n);
    for(int i=0;i<n;i++) suffs[i]={{s[i],s[i]},i};
    sort(all(suffs));
    vt<int>ranks(n);
    ranks[suffs[0].se]=0;
    for(int i=1;i<n;i++)
    {
        ppi c=suffs[i];
        ppi p=suffs[i-1];
        ranks[c.se]=ranks[p.se]+(c.fi>p.fi);
    }
    for(int k=1;k<n;k*=2)
    {
        for(auto &[val,i]:suffs) val={ranks[i],ranks[(i+k)%n]};
        
        radix_sort(suffs);
        
        ranks[suffs[0].se]=0;
        for(int i=1;i<n;i++)
        {
            ppi c=suffs[i];
            ppi p=suffs[i-1];
            ranks[c.se]=ranks[p.se]+(c.fi>p.fi);
        }
    }
//    for(int i=0;i<n;i++) cout<<suffs[i].se<<' ';
    
    idx_suffs.resize(n);
    for(int i=0;i<n;i++) idx_suffs[suffs[i].se]=i;
    vt<int> lcp(n-1);
    int start=0;
    for(int i=0;i<n-1;i++)
    {
        int pre=suffs[idx_suffs[i]-1].se;
        int k=start;
        while(s[i+k]==s[pre+k]) k++;
        lcp[idx_suffs[i]-1]=k;
        start=max(k-1,0);
    }
//    for(int i=0;i<n-1;i++) cout<<lcp[i]<<' ';
    
//    ll ans=(n*(n-1)/2);
//    for(int i=0;i<n-1;i++) ans-=lcp[i];
//    cout<<ans;
    
    memset(rmq,0,sizeof(rmq));
    for(int i=0;i<n-1;i++) rmq[i][0]=lcp[i];
    for(int k=1;(1<<k)<n;k++)
        for(int i=0;i+(1<<k)-1<n-1;i++)
            rmq[i][k]=min(rmq[i][k-1],rmq[i+(1<<(k-1))][k-1]);

    int m;
    cin>>m;
    vt<pii> sub(m);
    for(int i=0;i<m;i++) 
    {
        cin>>sub[i].fi>>sub[i].se;
        sub[i].fi--;
        sub[i].se--;
    }
    sort(all(sub),cmp);
    for(auto x:sub) cout<<x.fi+1<<' '<<x.se+1<<'\n';
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
//https://codeforces.com/edu/course/2/lesson/2/5/practice/contest/269656/problem/C
