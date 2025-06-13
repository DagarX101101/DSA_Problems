#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define inputv(v)     \
    for (auto &i : v) \
        cin >> i;
#define all(v) v.begin() v.end()
#define int long long

void solve(vector<vi> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            swap(v[i][j], v[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(v[i][j], v[i][n - j - 1]);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vi> v(n, vi(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    solve(v);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
