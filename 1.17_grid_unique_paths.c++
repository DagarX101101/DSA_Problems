#include <bits/stdc++.h>
using namespace std;
int grid_path(int n, int m, int i, int j)
{
    if (i == n || j == m)
    {
        return 0;
    }
    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }
    return grid_path(n, m, i + 1, j) + grid_path(n, m, i, j + 1);
}
int optimal(int n, int m)
{
    int N = n + m - 2;
    int r = m - 1;
    double ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans = ans * (N - r + i) / i;
    }
    return (int)ans;
}
int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    int ans = optimal(n, m);
    cout << ans;
    return 0;
}