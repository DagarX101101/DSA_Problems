#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void naiveapp(int arr[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                cnt++;
            }
        }
    }
    cout << cnt;
}
void mergeit(int arr[], int low, int mid, int high)
{
    vector<int> vec;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            vec.push_back(arr[left]);
            left++;
        }
        else
        {
            vec.push_back(arr[right]);
            cnt += mid - left + 1;
            right++;
        }
    }
    while (left <= mid)
    {
        vec.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        vec.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = vec[i - low];
    }
}
void count_merge_sort_(int arr[], int low, int high)
{
    int mid = (low + high) / 2;
    if (low >= high)
    {
        return;
    }
    count_merge_sort_(arr, low, mid);
    count_merge_sort_(arr, mid + 1, high);
    mergeit(arr, low, mid, high);
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
    // naiveapp(arr, n);
    count_merge_sort_(arr, 0, n - 1);
    cout << cnt;
    return 0;
}