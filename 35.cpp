
#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:



    int searchInsert(vector<int>&nums, int target){

        int  l  =0;
        int  r = nums.size() - 1;

         
        if(nums[0] > target) return 0;
        if(nums[r] < target) return nums.size();

        while (r >= l) {
            int mid =   l + (r - l) / 2;


            if(nums[mid] == target) return mid;
            cout<<mid<<endl;
            if(target > nums[mid]){
                l = mid  + 1;
            }
            else {
                r = mid - 1;
            }



        }

        return l ;



    }


};



int main(){

    Solution s;

    vector<int> nums = {1,3,5,6};

    int ans = s.searchInsert(nums,  5);


    cout<<ans<<endl;

    return 0; 
}