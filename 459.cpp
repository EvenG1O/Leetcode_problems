#include <iostream>
#include <string>
#include <vector>


using  namespace  std;

bool repeatedSubstringPatter(string s)
{

    string  temp  = s + s;

    string temp2 = temp.substr(1,temp.size() - 2);

    return temp2.find(s) != string::npos;
}

int main()
{

    string  s = "aba";

    bool ans = repeatedSubstringPatter(s);


    cout<<ans;


    return 0;
}