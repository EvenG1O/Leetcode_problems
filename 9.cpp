#include <iostream>
#include <string>



class Solution {
public:
    bool isPalindrome(int x) {
        std::string curr = std::to_string(x);
        
        int l{};
        int r = curr.length()-1;

        while(l < r){
            if(curr[l] != curr[r]){
                return false;

            }
            l++;
            r--;
        }
        return true;


    }
};


int main(){

    Solution s;

    int test{-121};

    bool ans = s.isPalindrome(test);

    std::cout<<std::boolalpha<<ans<<std::endl;


    return 0;
}