#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
vi optimal(vi &arr, int n, int target)
{
    int i = 0;
    int j = n - 1;
    sort(arr.begin(), arr.end());
    ` while (i < j)
    {
        if (arr[i] + arr[j] == target)
        {
            return {i, j};
        }
        if (arr[i] + arr[j] < target)
        {
            i++;
        }
        if (arr[i] + arr[j] > target)
        {
            j--;
        }
    }
    return {-1, -1};
}
vi solve(vi &vec, int n, int target) // hashing(imp)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int x = target - vec[i];
        if (mpp.find(x) != mpp.end())
        {
            return {mpp[x], i};
        }
        mpp[vec[i]] = i;
    }
    return {-1};
}
int main()
{
    int n;
    cin >> n;
    int target;
    cin >> target;
    vi vec(n);
    for (auto &it : vec)
    {
        cin >> it;
    }
    vi sol = optimal(vec, n, target);
    for (auto it : sol)
    {
        cout << it << "  ";
    }
}