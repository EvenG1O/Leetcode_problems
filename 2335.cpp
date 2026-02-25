#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using  namespace std;


int fillCups(vector<int> &amount)
{
   sort(amount.begin(),amount.end());

   if(amount[2] > amount[0] + amount[1]) return amount[2];
   else return (amount[2] + amount[1] +  amount[0]) / 2 + (amount[2] + amount[1] +  amount[0]) % 2; 
    

}


int main()
{

    vector<int> test = {5,4,4};

    int ans = fillCups(test);

    cout<<ans;


    return 0;
}