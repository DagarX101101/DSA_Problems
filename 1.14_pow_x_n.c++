#include <bits/stdc++.h>
using namespace std;
double power(int x, int n)
{
    double ans = 1;
    long long nn = n;
    if (n < 0)
    {
        nn = -1 * nn;
    }
    while (nn > 0)
    {
        if (nn % 2 == 1)
        {
            ans = ans * x;
            nn = nn - 1;
        }
        if (nn % 2 == 0)
        {
            x = x * x;
            nn = nn / 2;
        }
    }
    if (n < 0)
    {
        ans = (double)(1.0) / (double)(ans);
    }
    return ans;
}
int main()
{
    int x;
    cin >> x;
    int n;
    cin >> n;
    cout << power(x, n);
}