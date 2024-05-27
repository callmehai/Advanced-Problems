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
#define ll long long
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
void radix_sort(vt<ppi> &arr)
{
    for(int i=1;i<=2;i++)
    {
        auto key =[&](const ppi&x)
        {
            return i==1?x.fi.se:x.fi.fi;
        };
        
        int m=0;
        for(auto x:arr) maximize(m,key(x));
        vt<int> cnt(m+1);
        for(auto &x:arr) cnt[key(x)]++;
        vt<int> start(m+1);
        for(int j=1;j<=m;j++) start[j]=start[j-1]+cnt[j-1];
        vt<ppi> new_arr(arr.size());
        for(auto x:arr)
            new_arr[start[key(x)]++]=x;
        swap(arr,new_arr);
    }
}
int main(){
    FPTU;

    string s;
    cin>>s;
    s+='$';
    ll n=(ll)s.size();
    vt<ppi> suffs(n);
    for(int i=0;i<n;i++) suffs[i]={{s[i],s[i]},i};
    sort(all(suffs));
    vt<int>ranks(n);
    for(int i=1;i<n;i++)
    {
        ppi c=suffs[i];
        ppi p=suffs[i-1];
        ranks[c.se]=ranks[p.se]+(c.fi>p.fi);
    }
    for(int k=1;k<n;k*=2)
    {
        for(auto &[val,i]:suffs)
            val={ranks[i],ranks[(i+k)%n]};
        
        radix_sort(suffs);
        
        for(int i=1;i<n;i++)
        {
            ppi c=suffs[i];
            ppi p=suffs[i-1];
            ranks[c.se]=ranks[p.se]+(c.fi>p.fi);
        }
    }
    vt<int> suffs_idx(n);
    for(int i=0;i<n;i++) suffs_idx[suffs[i].se]=i;
    vt<int> lcp(n-1);
    int start=0;
    for(int i=0;i<n-1;i++)
    {
        int pre=suffs[suffs_idx[i]-1].se;
        int k=start;
        while(s[i+k]==s[pre+k]) k++;
        lcp[suffs_idx[i]-1]=k;
        start=max(k-1,0);
    }
    ll diff_substr=n*(n-1)/2;
    for(int i=0;i<n-1;i++) diff_substr-=lcp[i];
    cout<<diff_substr;
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
//https://judge.yosupo.jp/problem/number_of_substrings
