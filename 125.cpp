#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {

        string currString{};

        for (char currChar : s)
        {

            if (isalnum(static_cast<char>(currChar)))
                currString.push_back(static_cast<unsigned char>(static_cast<unsigned char>(tolower(currChar))));
        }

        int l{};
        int r = currString.size() - 1;

        while (l <= r)
        {

            if (currString[l] != currString[r])
            {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};

int main()
{
    Solution s;
    string test = "A man, a plan, a canal: Panama";

    bool ans = s.isPalindrome(test);

    cout << boolalpha << ans << endl;

    return 0;
}