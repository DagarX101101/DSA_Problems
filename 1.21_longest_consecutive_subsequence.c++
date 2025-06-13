#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
bool ls(vi &arr, int z)
{
    int n = arr.size();
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == z)
        {
            found = true;
            break;
        }
    }
    return found;
}
int solve(vi &arr)
{
    int n = arr.size();
    int length = 1;
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        int x = arr[i];
        while (ls(arr, x + 1) == true)
        {
            x = x + 1;
            cnt++;
        }
        length = max(length, cnt);
    }
    return length;
}
int better(vi &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int cnt = 1;
    int longest = 1;
    int i = 1;
    while (i < n)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            i++;
            continue;
        }
        if (arr[i] == arr[i - 1] + 1)
        {
            cnt++;
            longest = max(cnt, longest);
            i++;
        }
        if (arr[i] > arr[i - 1] + 1)
        {
            cnt = 1;
            i++;
        }
    }
    return longest;
}
bool find(unordered_set<int> hashset, int x)
{
    if (hashset.find(x) != hashset.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int optimal(vi &arr)
{
    int n = arr.size();

    int longest = 1;
    unordered_set<int> hashset;
    for (int i = 0; i < n; i++)
    {
        hashset.insert(arr[i]);
    }

    for (auto i : hashset)
    {
        int cnt = 1;
        if (hashset.find(i - 1) != hashset.end())
        {
            continue;
        }
        else
        {
            int x = i + 1;
            while (find(hashset, x) == true)
            {
                cnt++;
                x++;
                longest = max(longest, cnt);
            }
        }
    }
    return longest;
}
int main()
{
    int n;
    cin >> n;
    vi vec(n);
    for (auto &it : vec)
    {
        cin >> it;
    }
    cout << solve(vec);
    cout << endl;
    cout << better(vec);
    cout << endl;
    cout << optimal(vec);
    return 0;
}