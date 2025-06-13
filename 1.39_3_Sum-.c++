#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
vvi better(vi &arr, int n, int x)
{
    set<vi> st;
    for (int i = 0; i < n; i++)
    {
        set<long long> hashset;
        for (int j = i + 1; j < n; j++)
        {

            long long sum = arr[i] + arr[j];
            long long l = x - sum;
            if (hashset.find(l) != hashset.end())
            {
                vi temp = {arr[i], arr[j], l};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vvi ans(st.begin(), st.end());
    return ans;
}
vvi solve(vi &arr, int n, int x) // bruteforce
{
    set<vi> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {

                long long sum = arr[i] + arr[j] + arr[k];
                if (sum == x)
                {
                    vi temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vvi ans(st.begin(), st.end());
    return ans;
}
vvi optimal(vi &arr, int n, int x)
{
    vvi st;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {

        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            long long sum = arr[i] + arr[j] + arr[k];
            if (sum == x)
            {
                vi temp = {arr[i], arr[j], arr[k]};
                st.push_back(temp);
                int arrk = arr[k];
                int arrj = arr[j];
                while (arr[j] == arrj)
                {
                    j++;
                }
                while (arr[k] == arrk)
                {
                    k--;
                }
            }
            if (sum < x)
            {
                int arrj = arr[j];
                while (arr[j] == arrj)
                {
                    j++;
                }
            }
            if (sum > x)
            {
                int arrk = arr[k];
                while (arr[k] == arrk)
                {
                    k--;
                }
            }
        }
    }
    return st;
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
    // vvi ans = solve(vec, n, target);
    // vvi ans = better(vec, n, target);
    vvi ans = optimal(vec, n, target);
    for (auto row : ans)
    {
        for (auto it : row)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}