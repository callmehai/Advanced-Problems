//#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;
 
// ************ Define ************
#define ll  long long
#define ull unsigned long long
#define usi unsigned int
#define pii pair<int,int>
#define pll pair<ll,ll>
#define plp pair<ll,pll>
#define ppl pair<pll,ll>
#define ppp pair<pii,pii>
#define oo  1000111000
#define ooo 1000111000111000111
#define inf 0x3f
#define INF 4557430888798830399
#define fi  first
#define se  second
#define vt  vector
#define pb  push_back
#define el  cout<<'\n';

#define all(arr)  arr.begin(),arr.end()
#define bit(n, i) (((n) >> (i)) & 1)
#define BUG(x)    cerr << #x << " = " << x << '\n';
#define FPTU      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int mod = 1e9+7; //MODDDDDDDDDDDDD

// =========> <3 VietHai1709 <3  <=======
int rowMask[9], colMask[9], blockMask[9];
int board[9][9];
vector<pair<int,int>> empties;

bool dfs(int idx) {
    if((1.0 * clock() / CLOCKS_PER_SEC) > 5.0) {
        cerr<<"Maybe no solution !\n";
        return false;
    }
    if (idx == empties.size()) return true;
    auto [r, c] = empties[idx];
    int b = (r/3)*3 + (c/3);
    int mask = (rowMask[r] | colMask[c] | blockMask[b]) ^ ((1<<10)-2);
    while (mask) {
        int bit = mask & -mask;
        mask -= bit;
        int d = __builtin_ctz(bit);
        board[r][c] = d;
        rowMask[r] |= bit;
        colMask[c] |= bit;
        blockMask[b] |= bit;
        if (dfs(idx + 1)) return true;
        rowMask[r] ^= bit;
        colMask[c] ^= bit;
        blockMask[b] ^= bit;
    }
    return false;
}
void solve() {
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            cin >> board[i][j];

    for (int i = 0; i < 9; ++i) {
        rowMask[i] = colMask[i] = blockMask[i] = 0;
    }
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0) {
                empties.emplace_back(i, j);
            } else {
                int d = board[i][j];
                int bit = 1 << d;
                rowMask[i] |= bit;
                colMask[j] |= bit;
                blockMask[(i/3)*3 + (j/3)] |= bit;
            }
        }
    }

    int ok = dfs(0);

    if(!ok){
        cout<<-1;
        return;
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << ' ';
        }
        el;
    }
}
int main()
{
    
    FPTU;
    freopen("sample.inp", "r", stdin);
    freopen("sample.out", "w", stdout);
    
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    cerr << "\nTime elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";

    return 0;
}
    
