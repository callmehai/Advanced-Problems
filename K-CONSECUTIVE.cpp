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
ll k,n,mod=1e9+7,M=1e9+6,a[111];
struct xx
{
    ll W,L;
    ll mat[102][102];
};
xx A,T;
ll poww(ll a,ll b)
{
    if(b==0) return 1;
    if(b==1) return a%mod;
    ll p=poww(a,b/2);
    if(b&1) return p*p%mod*a%mod;
    return p*p%mod;
}
ll mul_mod(ll a,ll b,ll MOD)
{
    if(b==0) return 0;
    if(b==1) return a%MOD;
    
    ll c=mul_mod(a,b/2,MOD);
    if(b&1) return (c+c+a)%MOD;
    return (c+c)%MOD;
}
xx mul_mat(xx B, xx C)
{
    xx D;
    D.W=B.W;
    D.L=C.L;
    memset(D.mat,0,sizeof(D.mat));
    
    ll z=B.L;
    
    for(int i=1;i<=D.W;i++)
        for(int j=1;j<=D.L;j++)
            for(int k=1;k<=z;k++)
            {
                D.mat[i][j]+=(B.mat[i][k]*C.mat[k][j]%M);
                if(D.mat[i][j]>=M) D.mat[i][j]-=M;
            }
    return D;
}
xx pow_mat(xx B,ll p) // square matrix
{
    if(p==1) return B;
    if(p==0)
    {
        xx I;
        ll n=B.W;
        memset(I.mat,0,sizeof(I.mat));
        for(int i=1;i<=n;i++) I.mat[i][i]=1;
        I.W=I.L=n;
        return I;
    }
    xx C=pow_mat(B,p/2);
    C.L=C.W=B.L;
    if(p&1) return mul_mat(mul_mat(C,C),B);
    return mul_mat(C,C);
}
int main(){
    FPTU;

    cin>>n>>k;
    for(int i=1;i<=k;i++) cin>>a[i];
    
    // transform
    T.W=k+1;
    T.L=k+1;
    memset(T.mat,0,sizeof(T.mat));
    for(int i=2;i<=k+1;i++) T.mat[i][i-1]=1;
    T.mat[1][k+1]=M-1;
    T.mat[k+1][k+1]=2;

    //base
    A.W=k;
    A.L=k+1;
    memset(A.mat,0,sizeof(A.mat));

    for(int i=1;i<=k;i++) A.mat[i][i]=1;
    for(int i=1;i<=k;i++) A.mat[i][k+1]=1;
    
    T=pow_mat(T,n-k-1);
    A=mul_mat(A,T); // [k,k+1]*[k+1,k+1] = [k,k+1]
    ll ans=1;
    for(int i=1;i<=k;i++)
    {
        ans=ans*poww(a[i],A.mat[i][k+1])%mod;
    }
    cout<<ans;
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
//https://dtqg.contest.codeforces.com/group/PObOuMCXsC/contest/413964/problem/C
