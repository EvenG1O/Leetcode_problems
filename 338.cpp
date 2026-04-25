#include <cmath>
#include <iostream>
#include <vector>


using  namespace  std;


class Solution{
    public:
    
    vector<int> countBits(int n){
        vector<int> ans(n+1);
        for(int num =1; num <= n; num++)
        {

            for(int i =0; i < 32; i++){

                if(num & (1 << i)) ans[num]++;


            }



        }
        return ans;

    }




};




int main()
{

    Solution S;

    vector<int> ans= S.countBits(2);

    for(int x : ans)
    {
        cout<<x<<endl;
    }


    return 0;
}