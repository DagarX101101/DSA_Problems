#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 2 1 5 4 3 0 0
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    int ind = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (vec[i + 1] > vec[i])
        {
            ind = i;
            break;
        }
    }
    if (ind != -1)
    {
        for (int i = n - 1; i > ind; i--)
        {
            if (vec[i] > vec[ind])
            {
                swap(vec[ind], vec[i]);
                break;
            }
        }
    }
    reverse(vec.begin() + ind + 1, vec.end());
    for (auto it : vec)
    {
        cout << it;
    }
    return 0;
}