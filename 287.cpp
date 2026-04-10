#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>


using  namespace  std;


int findDuplicate(vector<int> &nums)
{
    unordered_map<int, int> map;

    for (int x  : nums) {
        map[x] += 1;
        if(map[x] > 1) return x;
    }

    return -1;



}

int main()
{

  
    vector<int> test = {1,2,3,4,5,6,7,7};

    int ans = findDuplicate(test);

    cout<<ans;

    return 0;
}