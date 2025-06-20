#include <bits/stdc++.h>
using namespace std;
void combination_sum1(int arr[], int n, int i, vector<int> vec, int target)
{
    // basecase
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        for (auto it : vec)
        {
            cout << it;
        }
        cout << endl;
        return;
    }
    if (i == n)
    {
        return;
    }
    // recursion calls
    vec.push_back(arr[i]);
    target = target - arr[i];
    combination_sum1(arr, n, i, vec, target);
    vec.pop_back();
    target = target + arr[i];
    i = i + 1;
    combination_sum1(arr, n, i, vec, target);
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
    combination_sum1(arr, n, 0, vec, target);
    return 0;
}
