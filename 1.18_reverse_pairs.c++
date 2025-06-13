#include <bits/stdc++.h>
using namespace std;
int couunt(vector<int> &arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int cont = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] > 2 * arr[j])
        {
            j++;
            cont += mid - i + 1;
        }
        else
        {
            i++;
        }
    }
    return cont;
}
void merge(vector<int> &arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    vector<int> temp;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= high)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
int solve(vector<int> &vec, int low, int high)
{
    if (low == high)
    {
        return 0;
    }
    int cnt = 0;
    int mid = (low + high) / 2;
    cnt += solve(vec, low, mid);
    cnt += solve(vec, mid + 1, high);
    cnt += couunt(vec, low, mid, high);
    merge(vec, low, mid, high);
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto &it : vec)
    {
        cin >> it;
    }
    int ans = solve(vec, 0, n - 1);
    cout << ans;
    return 0;
}
