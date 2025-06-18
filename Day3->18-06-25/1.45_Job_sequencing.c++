#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define int long long

void solve()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int minMaxValue = INT_MAX;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            int Cm = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int val = arr[i][j];
                    if (i == r || j == c)
                    {
                        val--;
                    }
                    Cm = max(Cm, val);
                }
            }
            minMaxValue = min(minMaxValue, Cm);
        }
    }
    cout << minMaxValue << endl;
    return;
}
int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
