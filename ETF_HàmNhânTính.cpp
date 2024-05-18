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
ull a,b,mod=998244353;
const int N=5e6;
ull phi[N+5],iphi[N+5];
void sang_ETF()
{
    for(ull i=0;i<=N;i++) phi[i]=i;
    for(ull i=2;i<=N;i++)
        if(phi[i]==i)
            for(ull j=i;j<=N;j+=i)
                phi[j]-=phi[j]/i;
}

ull poww(ull a,ull b)
{
    if(b==1) return a;
    ull p=poww(a,b/2);
    if(b&1) return p*p%mod*a%mod;
    return p*p%mod;
}
int main(){
    FPTU;

    cin>>a>>b;
    sang_ETF();
    memset(iphi,0,sizeof(iphi));
    ull ans=0;
    for(ull i=1;i<=b;i++)
    {
        ull c=gcd(a,i);
        ull phi_ai=phi[a]*phi[i]%mod;
        if(c!=1)
        {
            if(iphi[c]==0) iphi[c]=poww(phi[c],mod-2);
            phi_ai=(phi_ai*c%mod*iphi[c]%mod);
        }
        ans+=phi_ai;
        if(ans>=mod) ans-=mod;
    }
    cout<<ans;
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
