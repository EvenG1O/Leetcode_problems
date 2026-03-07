#include <cmath>
#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

vector<vector<int>> KClosest(vector<vector<int>> &points, int k) {

  auto compare = [](tuple<vector<int>, int> a, tuple<vector<int>, int> b) {
    return get<1>(a) > get<1>(b);
  };

  priority_queue<tuple<vector<int>, int>, vector<tuple<vector<int>, int>>,
                 decltype(compare)>
      pq(compare);

  for (int i = 0; i < points.size(); i++) {
    int a =  pow((points[i][0] - 0) ,2) + pow((0 - points[i][1]) , 2);

    vector<int> temp2 = {points[i][0], points[i][1]};

    tuple<vector<int>, int> temp = {temp2, a};

    pq.push(temp);
  }

  vector<vector<int>> ans;


  while (k != 0 && !pq.empty()) {

    vector<int> temp3 = get<0>(pq.top());
    ans.push_back(temp3);
    pq.pop();
    k--;
  }

  return ans;
}

int main() { 
    



    vector<vector<int>> temp = {{3,3}, {5,-1}, {-2,4}};


    vector<vector<int>>ans = KClosest(temp, 2);

    for(int i =0 ; i < ans.size(); i++)
    {

        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;


    }


    
    
    return 0; 

}