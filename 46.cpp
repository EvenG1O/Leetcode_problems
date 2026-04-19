#include <algorithm>
#include <cstddef>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
    void backtrack(const vector<int> &nums, vector<int> &current, vector<bool> &b, vector<vector<int>> &ans)
    {

        if (current.size() == nums.size())
        {
            ans.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {

            if (!b[i])
            {

                current.push_back(nums[i]);
                b[i] = true;

                backtrack(nums, current, b);

                current.pop_back();

                b[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() <= 0)
            return ans;

        vector<bool> b(nums.size(), false);
        vector<int> curr;

        backtrack(nums, curr, b, ans);

        return ans;
    }
};

int main()
{

    Solution s;

    vector<int> t = {1, 2, 3};

    vector<vector<int>> ans = s.permute(t);

    for (size_t i = 0; i < ans.size(); i++)
    {

        for (int x : ans[i])
        {
            cout << x << endl;
        }
        cout << endl;
    }

    return 0;
}