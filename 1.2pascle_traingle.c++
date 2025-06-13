class Solution
{
public:
    vector<int> generate_rows(int numRows)
    {
        vector<int> vec;
        long long ans = 1;
        vec.push_back(1);
        for (int i = 1; i < numRows; i++)
        {
            ans = ans * (numRows - i);
            ans = ans / i;
            vec.push_back(ans);
        }
        return vec;
    }
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> arr;
        for (int i = 1; i <= numRows; i++)
        {
            arr.push_back(generate_rows(i));
        }
        return arr;
    }
};