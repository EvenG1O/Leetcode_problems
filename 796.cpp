#include <iostream>
#include <vector>


using  namespace  std;


bool rotateString(string s,  string  goal)
{
    if(s.size() != goal.size()) return false;

    int size = s.size();
    string ans = s;

    while (size != 0) {
        if(ans == goal) return true;

        ans = ans.substr(1) + ans[0];
        size--;
    }

    return false;



}


int main()
{
    bool ans = rotateString("abcde", "abced");


    cout<<ans;




    return 0;
}