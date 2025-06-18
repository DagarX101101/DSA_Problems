#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Job
{
    int id;
    int deadline;
    int profit;
};
bool comparator(Job a, Job b)
{
    return (a.profit > b.profit);
}
void optimasl(Job arr[], int n)
{
    sort(arr, arr + n, comparator);
    int maxi = arr[0].deadline;
    for (int i = 0; i < n; i++)
    {
        maxi = max(arr[i].deadline, maxi);
    }
    int slot[maxi + 1];
    for (int i = 0; i <= maxi; i++)
    {
        slot[i] = -1;
    }
    int countjobs = 0;
    int jobprofit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = arr[i].id;
                countjobs++;
                jobprofit += arr[i].profit;
                break;
            }
        }
    }
    cout << jobprofit <<"\n";
    cout << countjobs <<"\n";
    for (int i = 0; i <= maxi; i++)
    {
        if (slot[i] != -1)
        {
            cout << slot[i] << " ";
        }
    }
    return;
}
int32_t main()
{
    int n;
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id >> arr[i].deadline >> arr[i].profit;
    }
    optimasl(arr, n);
    return 0;
}
