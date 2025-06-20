#include <bits/stdc++.h>
using namespace std;
void combination_sum2(int arr[], int n, int ind, vector<int> vec, int target, vector<vector<int>> &ans)
{
    // basecase
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        ans.push_back(vec);
        return;
    }
    if (ind == n)
    {
        return;
    }
    // recursion calls
    for (int i = ind; i < n; i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
        {
            continue;
        }
        vec.push_back(arr[i]);
        combination_sum2(arr, n, i + 1, vec, target - arr[i], ans);
        vec.pop_back();
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    vector<int> vec;
    vector<vector<int>> ans;
    combination_sum2(arr, n, 0, vec, target, ans);
    for (auto &row : ans)
    {
        for (auto it : row)
        {
            cout << it;
        }
        cout << endl;
    }
    return 0;
}
