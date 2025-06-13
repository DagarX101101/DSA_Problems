#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define int long long
int solve(string str)
{
    int n = str.size();
    int left = 0;
    int right = 0;
    set<char> st;
    int length = 0;
    while (right < n)
    {
        while (right < n && (st.find(str[right]) == st.end()))
        {
            length = max(length, right - left + 1);
            st.insert(str[right]);
            right++;
        }
        while (right < n && (st.find(str[right]) != st.end()))
        {
            int x = str[left];
            st.erase(x);
            left++;
        }
    }
    return length;
}
int optimal(string str)
{
    int n = str.size();
    int left = 0;
    int right = 0;
    map<char, int> mpp;
    int length = 0;
    while (right < n)
    {
        while (right < n && ((mpp[str[right]] >= left) && (mpp[str[right] <= right])))
        {
            mpp[arr[right]] = right;
            length = max(length, right - left + 1);
            right++;
        }
    }
}
int32_t main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    cout << solve(str);
    return 0;
}