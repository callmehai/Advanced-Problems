#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 4067;
int n, a[N];
string s;
ll mod = 1e9 + 7, base = 97;
ll L[N], R[N], poww[N], MM;
ll get_hash_left(int i, int j)
{
    return (L[j] - (L[i - 1] * poww[j - i + 1] % mod) + MM) % mod;
}
ll get_hash_right(int i, int j)
{
    return (R[i] - (R[j + 1] * poww[j - i + 1] % mod) + MM) % mod;
}
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
}
void solve()
{
    cin >> n;
    cin >> s;
    poww[0] = 1;
    MM = mod * mod;
    for (int i = 1; i <= n; i++)
    {
        a[i] = s[i - 1] - 'a' + 1;
        poww[i] = poww[i - 1] * base % mod;
        L[i] = (L[i - 1] * base + a[i]) % mod;
    }
    for (int i = n; i >= 1; i--)
        R[i] = (R[i + 1] * base + a[i]) % mod;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = min(i - 1, n - i);
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (get_hash_left(i, i + mid) == get_hash_right(i - mid, i))
            {
                ans = max(ans, mid * 2 + 1);
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
    }
    for (int i = 1; i < n; i++)
        if (a[i] == a[i + 1])
        {
            int l = 0, r = min(i - 1, n - i - 1);
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (get_hash_left(i + 1, i + 1 + mid) == get_hash_right(i - mid, i))
                {
                    ans = max(ans, mid * 2 + 2);
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
        }
    cout << ans;
}
int main()
{
    //fast();
    solve();
    return 0;
}
//https://oj.vnoi.info/problem/paliny
