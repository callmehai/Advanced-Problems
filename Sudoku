/* Do not complain, work harder.
*******************************************************************
*                                             _|                  *
*  _|        _|   _|_|    _|                _|_|_|                *
*   _|      _|    _| _|   _|          _|_|_|_|_|_|_|_|_|          *
*   _|      _|    _|  _|  _|            _|_|_|_|_|_|_|            *
*    _|    _|     _|   _| _|              _|_|_|_|_|              *
*     _|  _|      _|    _|_|            _|_|_|  _|_|_|            *
*       _|        _|      _|          _|_|_|      _|_|_|          *
*******************************************************************
*                                                                 *
* _|      _|   _|   _|_|_|   _|_|_|_|   _|    _|     _|_|     _|  *
* _|      _|   _|   _|          _|      _|    _|   _|    _|   _|  *
*  _|    _|    _|   _|_|_|      _|      _|_|_|_|   _|_|_|_|   _|  *
*   _|  _|     _|   _|          _|      _|    _|   _|    _|   _|  *
*     _|       _|   _|_|_|      _|      _|    _|   _|    _|   _|  *
*                                                                 *
*******************************************************************/
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
#define oo 1000111000
#define ooo 1000111000111000111
#define fi first
#define se second
#define pri_qu priority_queue
#define vt vector
#define pb push_back
#define all(arr) arr.begin(),arr.end()
template <typename T> void minimize(T &a, T b){ if(a>b) a=b;}
template <typename T> void maximize(T &a, T b){ if(a<b) a=b;}
bool bit(ll a,int i) { return a>>i&1; }
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

const int N=10;
int a[N][N],b[N][N];
int row[N][N],col[N][N],block[N][N];
int n=9;
int cnt=0;
// =========> <3 VietHai1709 <3  <=======
int O(int i,int j)
{
    if(i<=3)
    {
        if(j%3==0) return j/3;
        return j/3+1;
    }
    if(i<=6)
    {
        if(j%3==0) return 3+j/3;
        return 3+j/3+1;
    }
    if(j%3==0) return 6+j/3;
    return 6+j/3+1;
    
}

void sudoku(int i,int j,int x)
{
    row[i][x]++;
    col[j][x]++;
    int z=O(i,j);
    block[z][x]++;
}
void resudoku(int i,int j,int x)
{
    a[i][j]=0;
    row[i][x]--;
    col[j][x]--;
    int z=O(i,j);
    block[z][x]--;
}
bool canfill()
{
    bool ok=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(a[i][j]==0)
        {
            int dem=0;
            int z=O(i,j);
            int save=0;
            for(int k=1;k<=9;k++)
                if(!row[i][k]&&!col[j][k]&&!block[z][k])
                {
                    dem++;
                    save=k;
                }
            if(dem==1)
            {
                ok=1;
                a[i][j]=save;
                sudoku(i,j,a[i][j]);
            }
        }
    return ok;
}
vt<ppi> prefill()
{
    bool ok=1;
    vt<ppi> ans;
    ans.clear();
    while(ok)
    {
        ok=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) if(a[i][j]==0)
            {
                int dem=0;
                int z=O(i,j);
                int save=0;
                for(int k=1;k<=9;k++)
                    if(!row[i][k]&&!col[j][k]&&!block[z][k])
                    {
                        dem++;
                        save=k;
                    }
                if(dem==1)
                {
                    ok=1;
                    a[i][j]=save;
                    sudoku(i,j,a[i][j]);
                    ans.pb({{i,j},a[i][j]});
                }
            }
    }
    return ans;
}
bool dq(int i,int j)
{
    if(j==10)
    {
        j=1;
        i++;
    }
    if(i==10) return 1;
    if(a[i][j]!=0) return dq(i,j+1);
    for(int k=1;k<=n;k++)
        if(!row[i][k]&&!col[j][k]&&!block[O(i,j)][k])
        {
            a[i][j]=k;
            sudoku(i,j,k);
            vt<ppi> save;
            save.clear();
            save=prefill();
            if(dq(i,j+1)) return 1;
            resudoku(i,j,k);
            for(ppi it:save)
            {
                
                resudoku(it.fi.fi,it.fi.se,it.se);
            }
        }
    return 0;
}
int main()
{
    FPTU;
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    for(int i=1;i<=9;i++)
       {
           for(int k=1;k<=9;k++)
               row[i][k]=col[i][k]=block[i][k]=0;
       }
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            int u;
            cin>>u;
            if(u==0)
            {
                a[i][j]=0;
                cnt++;
            }
            else
            {
                a[i][j]=u;
                sudoku(i, j, a[i][j]);
            }
        }
    }
    while(1)
    {
        if(!canfill()) break;
    }
    cout<<dq(1,1)<<'\n';
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++) cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
    
}



