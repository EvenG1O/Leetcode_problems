#include <iostream>
#include <cctype>


using  namespace std;


bool detectCapitalUse(string  word)
{
    bool flagupper = true;
    bool flaglower = true;
    bool flag = true;


    for(int i = 1; i < word.size(); i++)
    {
        if(isupper(word[i]))
        {
            flaglower = false;
            cout<<"it worked";
        }  
        cout<<word[i]<<endl;

    }

    cout<<endl;
    for(int i = 0; i < word.size(); i++)
    {
        if(islower(word[i])) 
        {
            flagupper = false;
            cout<<"it worked";
  
        }
        cout<<word[i]<<endl;
    }

    if(flaglower == false && flagupper == false) return false;

    return true;






}


int main()
{
    string test = "FlaG";

    bool  ans =  detectCapitalUse(test);

    if(ans) cout<<"working";
    else cout<<"not  working";




    return 0;
}