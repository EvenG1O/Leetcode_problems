#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;




class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int currMaxLen{};
        int l{};
        int r{};
        unordered_map<char, int> m;

        if(s.size() == 0) return 0;


        while(s.size() > r){
            if(m.count(s[r])){
                l = max(l, m[s[r]] +1); 
            }    
            m[s[r]] = r;

            currMaxLen = max(currMaxLen, r - l + 1);
            r++;
        }

        return currMaxLen;

    }
};


int main(){

    Solution s;

    string test  = "abcabcbb";

    int ans = s.lengthOfLongestSubstring(test);

    cout<<ans<<endl;

    return 0;
}