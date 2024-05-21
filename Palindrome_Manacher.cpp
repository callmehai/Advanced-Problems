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
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define db(x) cerr << #x << " = " << (x) << " ";

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
int n;
string s;
void manacher_odd(vt<int>&d)
{
    int L=1,R=0;
    for(int i=1;i<=n;i++)
    {
        if(i>R) d[i]=0;
        else d[i]=min(R-i,d[L+R-i]);
        while(i-d[i]-1>0&&i+d[i]+1<=n&&s[i-d[i]-1]==s[i+d[i]+1]) d[i]++;
        if(i+d[i]>R)
        {
            R=i+d[i];
            L=i-d[i];
        }
        
    }
}
void manacher_even(vt<int>&d)
{
    int L=1,R=0;
    for(int i=1;i<n;i++)
    {
        int j=i+1;
        if(j>R) d[i]=0;
        else d[i]=min(R-i,d[L+R-j]);
        while(i-d[i]>0&&j+d[i]<=n&&s[i-d[i]]==s[j+d[i]]) d[i]++;
        if(i+d[i]>R)
        {
            R=i+d[i];
            L=j-d[i];
        }
    }
}
int main(){
    FPTU;
    cin>>n>>s;
    s=' '+s;
    vt<int>D_odd(n+1);
    manacher_odd(D_odd);
    vt<int>D_even(n);
    manacher_even(D_even);
    int ans=D_odd[n]*2+1;
    for(int i=1;i<n;i++)
    {
        maximize(ans,D_odd[i]*2+1);
        maximize(ans,D_even[i]*2);
    }
    cout<<ans;
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
//https://oj.vnoi.info/problem/paliny
