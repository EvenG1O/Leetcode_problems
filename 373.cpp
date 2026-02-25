#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

vector<vector<int>> ksmallesPairs(vector<int> &nums1, vector<int> &nums2, int k)
{

    auto comparator = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b)
    {
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    };

    int m = nums1.size();
    int n = nums2.size();

    vector<vector<int>> result;

    priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(comparator)> minH(comparator);


    for(int i  =0; i < min(k,m); i++)
    {   
        minH.emplace(i,0);

    }

    while (k-- > 0 && !minH.empty()) {
        auto [index1, index2] = minH.top();
        minH.pop();

        result.push_back({nums1[index1], nums2[index2]});

        if(index2 + 1 < n)
        {
            minH.emplace(index1,index2 + 1);
        }
    }


    return result;
}


int main()
{

    // vectors
    vector<int> arr1 = {1,7,11};
    vector<int> arr2 = {2,4,6};

   vector<vector<int>> ans = ksmallesPairs(arr1, arr2, 7);

   for (vector<int> x : ans) {

        for(int y : x){
            cout<<y<<endl;
        }
        cout<<endl;
   }






    return 0;
}