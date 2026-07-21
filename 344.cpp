#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int l{};
        int r = s.size() -1;

        while (l < r)
        {
            char c = s[l];
            s[l] = s[r];
            s[r] = c;
            r--;
            l++;
        }
        

    }
};




int main(){
    Solution s;
    vector<char> test = {'H','a','n','n','a','h'};

   s.reverseString(test);

   for(char c : test){

    cout<<c<<endl;
   }
    
    



    return 0;
}