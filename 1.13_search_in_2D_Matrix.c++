#include <bits/stdc++.h>
using namespace std;
void codeit(vector<vector<int>> &arr; int n; int m; int x)
{
    int i = 0;
    int j = m - 1;
    bool found = false;
    while (i < n && j >= 0)
    {
        if (x > arr[i][j])
        {
            i++;
        }
        else if (x < arr[i][j])
        {
            j--;
        }
        else
        {
            cout << "Yes";
            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "No";
    }
}
bool boolean_search_in_matrix(vector<vector<int>> &arr; int n; int m; int x)
{
    n = arr.size();
    m = arr[0].size();
    if (arr.size() == 0)
    {
        return false;
    }
    int low = 0;
    int high = n * m - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid / m][mid % m] == x)
        {
            return true;
        }
        if (arr[mid / m][mid % m] > x)
        {
            low = mid + 1;
        }
        if (arr[mid / m][mid % m] < x)
        {
            high = mid - 1;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int x;
    cin >> x;
    codeit(arr, n - 1, m - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}