#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define int long long
int solve(vi &arr, int k)
{
    int n = arr.size();
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                int l = j - i + 1;
                length = max(length, l);
                break;
            }
        }
    }
    return length;
}
int better(vi arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> mpp;
    int sum = 0;
    int length = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (mpp.find(sum) != mpp.end())
        {
            continue;
        }
        if (sum == k)
        {
            length = max(length, i + 1);
        }
        if (mpp.find(sum - k) != mpp.end())
        {
            length = max(length, i - mpp[sum - k] + 1);
        }
        mpp[sum] = i;
    }
    return length;
}
int32_t main()
{
    int n;
    cin >> n;
    vi vec(n);
    for (auto &it : vec)
    {
        cin >> it;
    }
    int k;
    cin >> k;
    cout << solve(vec, k);
    cout << endl;
    // cout << better(vec,k);
    // cout << endl;
    // cout << optimal(vec,k);
    return 0;
}