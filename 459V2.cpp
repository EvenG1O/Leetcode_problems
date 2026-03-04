#include <iostream>
#include <string>
#include <vector>


using  namespace  std;


vector<int> buildLPS(string s)
{
    int n = s.size();
    vector<int> lps(n,0);

    int len = 0;
    int i  = 1;

    while (i < n) {
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }else {
            if(len != 0)
            len = lps[len -1];       
            else i++;
        }
    }

    return  lps;
}



bool repeatedSubstringPattern(string s)
{

        vector<int> lps = buildLPS(s);
    int n = s.size();
    int len = lps[n - 1];

    return (len > 0 && n % (n - len) == 0);
   

}

int main()
{

    string  s = "aa";

    bool ans = repeatedSubstringPattern(s);


    cout<<ans;


    return 0;
}