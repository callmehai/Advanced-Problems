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
#define event pair<pii,ull>
struct BIT{ // getmax
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

void Minnnnnnn()
{
    int n,m;
    cin>>n>>m;
    vt<vt<int>> station(n+1);
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        station[x].pb(i);
    }
    vt<ull> cnt(n+1);
    for(int i=1;i<=n;i++) cin>>cnt[i];
    int k;
    cin>>k;
    vt<event> E;
    for(int i=1;i<=k;i++){
        int l,r;
        ull c;
        cin>>l>>r>>c;
        E.pb({{l,r},c});
    }
    vt<int> ans(n+1,oo);
    vt<int> dl(n+1,1);
    vt<int> dr(n+1,k);
    vt<vt<int>> v(k+1);
    while(1){
        BIT myTree(m+1);
        bool ok=0;
        
        for(int i=1;i<=n;i++) 
            if(dl[i]<=dr[i]){
                ok=1;
                v[(dl[i]+dr[i])/2].pb(i);
            }
                
        if(!ok) break;
        for(int i=1;i<=k;i++){
            int l=E[i-1].fi.fi;
            int r=E[i-1].fi.se;
            ull val=E[i-1].se;
            if(l<=r)
            {
                myTree.up(l,val);
                myTree.up(r+1,-val);
            }
            else{
                myTree.up(l,val);
                //myTree.up(m+1,-val);// not nessesary
                myTree.up(1,val);
                myTree.up(r+1,-val);
            }
//            cout<<"Step "<<i<<":"<<'\n';
//            for(int i=1;i<=m;i++) cout<<ST.get(1,1,m,i)<<' ';
//            cout<<'\n';
            while(!v[i].empty()){
                int cur=v[i].back();
                v[i].pop_back();
                ull sum=0;
                for(int u:station[cur]){
                    sum+=myTree.get(u);
                }
                if(sum>=cnt[cur]){
                    ans[cur]=min(ans[cur],i);
                    dr[cur]=i-1;
                }
                else{
                    dl[cur]=i+1;
                }
                //cout<<cur<<' '<<sum<<'\n';
            }
        }
    }
    for(int i=1;i<=n;i++) if(ans[i]==oo) cout<<"NIE\n";
    else cout<<ans[i]<<'\n';
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
//https://www.spoj.com/problems/METEORS/
