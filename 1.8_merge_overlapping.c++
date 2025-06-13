#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define int long long
#define inputv(v)     \
    for (auto &i : v) \
        cin >> i;
#define all(v) v.begin(), v.end()

vector<vi> brutesolve(vector<vi> &v)
{
    int n = v.size();
    sort(all(v));
    vi arr;
    for (int i = 0; i < n; i++)
    {
        int start = v[i][0];
        int end = v[i][1];
        if (!ans.empty() && arr.back()[1] >= end)
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (v[j][0] <= end)
            {
                end = v[j][1];
            }
            else
            {
                break;
            }
        }
        arr.push_back({start, end});
    }
    return arr;
}
vector<vi> optimalsolve(vector<vi> &v)
{
    int n = v.size();
    sort(all(v));
    vi arr;
    for (int i = 0; i < n; i++)
    {
        if (arr.empty() || v[i][0] > arr.back())
        {
            arr.push_back(v[i]);
        }
        else
        {
            arr.back()[1] = max(arr.back()[1], v[i][1]);
        }
    }
    return arr;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vi> v(n, vi(2));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0];
        cin >> v[i][1];
    }
    // brutesolve(v);
    vector<vector<int>> ans = optimalsolve(v);
    for (auto &row : ans)
    {
        cout << row[0] << " " << row[1];
    }
    return 0;
}