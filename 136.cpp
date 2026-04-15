#include <iostream>
#include <vector>


using  namespace  std;


int singleNumber(vector<int> &nums){
    int ans = 0;

    for (int x  : nums) {
        ans ^= x;

    }

    return ans;

}



int main()
{

  vector<int> test = {2,2,1};

  int ans = singleNumber(test);

  cout<<ans<<endl;



    return 0;
}