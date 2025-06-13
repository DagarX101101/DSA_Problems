#include <bits/stdc++.h>
using namespace std;
void functifonn(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high) // O(N)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);

            mid++;
            low++;
        }
        if (arr[mid] == 1)
        {
            mid++;
        }
        if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
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
    functifonn(arr, n);
    return 0;
}