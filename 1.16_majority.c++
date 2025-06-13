#include <bits/stdc++.h>
using namespace std;
vector<int> majorityy__element(int arr[], int n)
{
    int min = n / 3 + 1;
    int el;
    vector<int> li;
    for (int i = 0; i < n; i++)
    {
        if (li.size() == 0 || li.back() != arr[i])
        {
            el = arr[i];
            int cnt = 0;
            for (int j = i; j < n; j++)
            {
                if (arr[j] == el)
                {
                    cnt++;
                }
                if (cnt == min)
                {
                    li.push_back(el);
                    break;
                }
            }
        }
    }
    return li;
}

vector<int> majority__element(int arr[], int n)
{
    // hashing;
    int min = n / 3 + 1;
    unordered_map<int, int> mpp;
    vector<int> li;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
        if (mpp[arr[i]] == min)
        {
            li.push_back(arr[i]);
        }
    }
    return li;
}
// Moore Voting Algorithm
void functifonn(int arr[], int n) // Moore's Voting Algorithm
{
    int el = 0;
    int cnt = 0;
    int i = 0;
    while (i < n)
    {
        if (arr[i] = el && cnt >= 0)
        {
            cnt++;
        }
        else if (arr[i] != el & cnt > 0)
        {
            cnt--;
        }
        else if (arr[i] != el && cnt == 0)
        {
            el = arr[i];
            cnt++;
        }
        i++;
    }
    int x = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
        {
            x++;
        }
    }

    if (x > n / 2)
    {
        cout << el;
    }
    else
    {
        cout << "doesn't exist";
    }
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
    vector<int> vec = majorityy__element(arr, n);
    for (auto it : vec)
    {
        cout << it << " ";
    }
}