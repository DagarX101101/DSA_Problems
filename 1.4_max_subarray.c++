#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define int long long
#define inputv(v)     \
    for (auto &i : v) \
        cin >> i;
#define all(v) v.begin(), v.end()

void solvebrute(vi &vec)
{
    int n = vec.size();
    // -2, -3, 4, -1, -2, 1, 5, -3
    int maxi = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + vec[j];
            maxi = max(maxi, sum);
        }
    }
    cout << maxi << endl;
}
void solveoptimal(vi &vec)
{
    // kadane algorithm
    int maxi = INT16_MIN;
    // -2 -3 4 -1 -2 1 5 -3
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxi = max(maxi, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    if (maxi < 0)
    {
        maxi == 0;
    }
    cout << maxi;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vi vec(n);
    inputv(vec);
    solvebrute(vec);
    solveoptimal(vec);
}