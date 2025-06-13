#include <bits/stdc++.h>
using namespace std;
void naiveapp(int arr[], int n)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            cout << arr[i];
            break;
        }
    }
}
void hashing(int arr[], int n)
{
    int hash[n + 1] = {0};
    for (int i = 0; i <= n; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] > 1)
        {
            cout << i;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }
    naiveapp(arr, n + 1);
    hashing(arr, n);
    return 0;
}