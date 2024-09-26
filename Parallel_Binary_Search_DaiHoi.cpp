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

struct DSU {
    int n;
    int cnt;
    vector<int> pa;
    DSU(int _n) {
        n = _n;
        cnt=n;
        pa.resize(n+1,-1);
    }
    int root(int u) {
        return pa[u] < 0 ? u : pa[u] = root(pa[u]);
    }
    int group_count(){
        return cnt;
    }
    int count(int u){
        return -pa[root(u)];
    }
    bool share(int u,int v){
        return root(u) == root(v);
    }
    bool merge(int u, int v) {
        u = root(u); v = root(v);
        if (u == v) return 0;
        if(pa[u] > pa[v]) swap(u,v);
        pa[u]+=pa[v]; pa[v]=u;
        cnt--;
        return 1;
    }
};
void Minnnnnnn()
{
    int n,m;
    cin>>n>>m;
    vt<pii> E(m);
    vt<vt<int>> vec(m+1);

    for(auto &[x,y] : E){
        cin>>x>>y;
    }
    int Q;
    cin>>Q;
    vt<int> dl(Q+1,1);
    vt<int> dr(Q+1,m);
    vt<ppi> query(Q+1);
    vt<int> ans(Q+1,m);
    for(int i=1;i<=Q;i++){
        cin>>query[i].fi.fi>>query[i].fi.se>>query[i].se;
    }
    while(1){
        DSU myDSU(n);
        bool ok=0;
        for(int i=1;i<=Q;i++){
            if(dl[i]<=dr[i]){
                ok=1;
                vec[(dl[i]+dr[i])/2].pb(i);
            }
        }
        if(!ok) break;
        for(int k=1;k<=m;k++){
            

            myDSU.merge(E[k-1].fi, E[k-1].se);
            
            while(!vec[k].empty()){
                int cur=vec[k].back();
                vec[k].pop_back();
                int u=query[cur].fi.fi;
                int v=query[cur].fi.se;
                int sum=query[cur].se;
                if(myDSU.share(u,v)){
                    sum-=myDSU.count(u);
                }
                else{
                    sum-=myDSU.count(u);
                    sum-=myDSU.count(v);
                }
                if(sum<=0){
                    ans[cur]=k;
                    dr[cur]=k-1;
                }
                else{
                    dl[cur]=k+1;
                }
            }
        }
    }
    for(int i=1;i<=Q;i++) cout<<ans[i]<<'\n';

    
}
int main(){
    FPTU;// read_file();
    int Test_case=1;
    //cin>>Test_case;
    while(Test_case--)
    {
        Minnnnnnn();
    }
    return 0;
}
//https://codeforces.com/group/sPSeeF9v8N/contest/367747/problem/A
