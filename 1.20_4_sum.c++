#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
vvi better(vi &arr, int n, int x)
{
    set<vi> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = arr[i] + arr[j] + arr[k];
                long long l = x - sum;
                if (hashset.find(l) == hashset.end())
                {
                    hashset.insert(arr[k]);
                }
                else
                {
                    vi temp = {arr[i], arr[j], arr[k], l};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                    hashset.insert(arr[k]);
                }
            }
        }
    }
    vvi ans(st.begin(), st.end());
    return ans;
}
vvi solve(vi &arr, int n, int x)
{
    set<vi> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if (sum == x)
                    {
                        vi temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
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
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
            {
                continue;
            }
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum == x)
                {
                    vi temp = {arr[i], arr[j], arr[k], arr[l]};
                    st.push_back(temp);
                    int arrk = arr[k];
                    int arrl = arr[l];
                    while (arr[k] == arrk)
                    {
                        k++;
                    }
                    while (arr[l] == arrl)
                    {
                        l--;
                    }
                }
                if (sum < x)
                {
                    int arrk = arr[k];
                    while (arr[k] == arrk)
                    {
                        k++;
                    }
                }
                if (sum > x)
                {
                    int arrl = arr[l];
                    while (arr[l] == arrl)
                    {
                        l--;
                    }
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