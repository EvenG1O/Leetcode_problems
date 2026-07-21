#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i{}; i < nums.size(); i++)
        {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r)
            {
                int currentSum = nums[i] + nums[l] + nums[r];

                if (currentSum < 0)
                {
                    l++;
                }
                else if (currentSum > 0)
                {
                    r--;
                }
                else
                {

                    ans.push_back({nums[i], nums[l], nums[r]});

                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> test = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = s.threeSum(test);

    for (vector<int> x : ans)
    {
        for (int curr : x)
        {
            cout << curr << " ";
        }
        cout << endl;
    }

    return 0;
}