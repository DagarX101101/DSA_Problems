#include <bits/stdc++.h>
using namespace std;
int majority__element(int arr[], int n)
{
    // hashing;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    int k = mpp.size();
    for (int i = 0; i < k; i++)
    {
        if (mpp[i] > n / 2)
        {
            return i;
        }
    }
    return -1;
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
        else if (arr[i] != el &&cnt = 0)
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
    cout << majority__element(arr, n);
}