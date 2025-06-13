#include <bits/stdc++.h>
using namespace std;
void markrow(int i, vector<vector<int>> &arr, int n, int m)
{
    for (int j = 0; j < m; j++)
    {
        if (arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}
void markcolumn(int j, vector<vector<int>> &arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}
void bruteforce(vector<vector<int>> &arr, int n, int m)
{
    vector<vector<int>> temp = arr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 0)
            {
                markrow(i, arr, n, m);
                markcolumn(j, arr, n, m);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
}
void better(vector<vector<int>> &arr, int n, int m) // O(N^2)
{
    int col[m] = {0};
    int row[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                col[j] = 1;
                row[i] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (col[j] == 1)
            {
                arr[i][j] = 0;
            }
            if (row[i] == 1)
            {
                arr[i][j] = 0;
            }
        }
    }
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

    // bruteforce(arr, n, m);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    better(arr, n, m);
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
