#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define inputv(v)     \
    for (auto &i : v) \
        cin >> i;
#define all(v) v.begin() v.end()
void solve(int arr1[], int n, int arr2[], int m)
{
    int arr3[n + m];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n || j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        if (arr1[i] > arr2[j])
        {
            arr3[k] = arr1[i];
            j++;
            k++;
        }
    }
    while (i < n)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while (j < m)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    for (int g = 0; g < n + m; g++)
    {
        if (g < n)
        {
            arr1[g] = arr3[g];
        }
        if (g > n)
        {
            arr2[g - n] = arr3[g];
        }
    }
}
void solve2(int arr1[], int n, int arr2[], int m)
{
    int left = 0;
    int right = 0;
    while (left < n)
    {
        if (arr1[left] <= arr2[right])
        {
            left++;
        }
        else
        {
            swap(arr1[left], arr2[right]);
            left++;
            sort(arr2, arr2 + m);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
}
void solveoptimal1(int arr1[], int n, int arr2[], int m)
{
    int left = n - 1;
    int right = 0;
    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++
        }
        else
        {
            break;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}
void swapfn(int arr1[], int ind1, int arr2[], int ind2)
{
    if (arr[ind1] > arr[ind2])
    {
        swap(arr1[ind1], arr2[ind2]);
    }
}
void solveoptimal2(int arr1[], int n, int arr2[], int m) // gap method
{                                                        // 1 3 5 7   // 0 2 6 8 9
    int ln = n + m;
    int gap = ln / 2 + ln % 2;
    int i = 0;
    int j = 0;
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < ln)
        {
            // arr1 and arr2
            if (left < n && right >= n)
            {
                swapfn(arr1, left, arr2, right - n);
            }
            // arr2 and arr2
            if (left >= n)
            {
                swapfn(arr1, left - n, arr2, right - n);
            }
            // arr1 and arr1
            if (right < n)
            {
                swapfn(arr1, left, arr2, right);
            }
            left++;
            right++;
        }
        if (gap == 1)
        {
            break;
        }
        gap = (gap / 2) + (gap % 2);
    }
}
int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr1[n];
    int m;
    cin >> m;
    int arr2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    solve2(arr1, n, arr2, m);
    return 0;
}