// https: // leetcode.com/problems/combination-sum-iii/description/


// logic:- use backtracking
class Solution
{
public:
    void helper(vector<vector<int>> &ans, vector<int> temp, int k, int n)
    {
        if (k == 0)
        {
            if (n == 0)
                ans.push_back(temp);
            return;
        }
        for (int i = temp.empty() ? 1 : temp.back() + 1; i <= 9; i++)
        {
            if (i > n)
                break;
            temp.push_back(i);
            helper(ans, temp, k - 1, n - i);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans, temp, k, n);
        return ans;
    }
};