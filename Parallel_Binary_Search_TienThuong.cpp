//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
//#incluse <bits/stdc++.h>
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
#define ll  long long
#define ull unsigned long long
#define usi unsigned int
#define pll pair<ll,ll>
#define plp pair<ll,pll>
#define ppl pair<pll,ll>
#define ppp pair<pii,pii>
#define oo 1000111000
#define ooo 1000111000111000111
#define inf 0x3f //4557430888798830399
#define fi first
#define se second
#define vt vector
#define pb push_back
#define all(arr) arr.begin(),arr.end()
#define bit(n, i) (((n) >> (i)) & 1)
#define db(x) cerr << #x << " = " << (x) << '\n';
random_device rd;
mt19937 mt(rd());
ll rand_num(ll a,ll b) {uniform_int_distribution<ll> dist(a,b);return dist(mt);}

int mod=1e9+7; // MODDDDDDDDDDDDD

template <typename T> void minimize(T &a, T b){ if(a>b)  a=b; }
template <typename T> void maximize(T &a, T b){ if(a<b)  a=b; }
template <typename T> void add(T &a, T b){ a+=b; if(a>=mod) a-=mod; }
template <typename T> T gcd(T a, T b){
    while(a!=0&&b!=0) if(a>b) a%=b; else b%=a; return a+b; }
void read_file()
{
    freopen("sample.inp","r",stdin);
    freopen("sample.out","w",stdout);
}
// =========> <3 VietHai1709 <3  <=========
struct BIT{
    vt<ull> A;
    int n;
    BIT(int _){
        n=_;
        A.resize(n+1,0);
    }
    void up(int x,ull val)
    {
        for(int i=x;i<=n;i+=(i&(-i))){
            A[i]+=val;
        }
    }
    ull get(int x){
        ull ans=0;
        for(int i=x;i>0;i-=(i&(-i))){
            ans+=A[i];
        }
        return ans;
    }
};
struct EulerTour{
    int n;
    vt<int> A;
    vt<int> end;
    vt<int> pos;
    vt<vt<int>> nxt;
    int flag=0;
    EulerTour(int _){
        n=_;
        A.resize(n+1);
        end.resize(n+1);
        pos.resize(n+1);
        nxt.resize(n+1);
    }
    void build(int u){
        pos[u]=++flag;
        A[flag]=u;
        for(int v : nxt[u]){
            build(v);
        }
        end[u]=flag;
    }
};

#define event pair<int,ull>
void Minnnnnnn()
{
    int n,q;
    cin>>n>>q;
    vt<ull> cnt(n+1);
    for(int i=1;i<=n;i++) {
        cin>>cnt[i];
    }
    EulerTour myEulerTour(n);
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        myEulerTour.nxt[x].pb(i);
    }
    myEulerTour.build(1);
//    for(int i=1;i<=n;i++) cout<<myEulerTour.pos[i]<<' '<<myEulerTour.end[i]<<'\n';
    vt<event> Event(q+1);
    for(int i=1;i<=q;i++){
        cin>>Event[i].fi>>Event[i].se;
    }
    vt<int> dl(n+1,1);
    vt<int> dr(n+1,q);
    vt<int> ans(n+1,-1);
    vt<vt<int>> vec(q+1);

    while(1){
        bool ok=0;
        for(int i=1;i<=n;i++){
            if(dl[i]<=dr[i]){
                ok=1;
                vec[(dl[i]+dr[i])/2].pb(i);
            }
        }
        
        if(!ok) break;
        
        BIT myBIT(n+1);
        for(int k=1;k<=q;k++){
            int node  = Event[k].fi;
            ull  val  = Event[k].se;
            myBIT.up(myEulerTour.pos[node],val);
            myBIT.up(myEulerTour.end[node]+1,-val);
            
            while(!vec[k].empty())
            {
                int u=vec[k].back();
                vec[k].pop_back();
                if(myBIT.get(myEulerTour.pos[u]) >= cnt[u]){
                    ans[u]=k;
                    dr[u]=k-1;
                }
                else{
                    dl[u]=k+1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<'\n';
}
int main(){
    FPTU; read_file();
    int Test_case=1;
    //cin>>Test_case;
    while(Test_case--)
    {
        Minnnnnnn();
    }
    return 0;
}
//https://codeforces.com/group/sPSeeF9v8N/contest/367747/problem/B
