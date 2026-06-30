#include <ios>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  set<int> s;

  unordered_map<int, vector<int>> m;

  bool dfs(int courseNumber, set<int> &visitSet) {

    if (s.count(courseNumber))
      return true;
    if (visitSet.count(courseNumber) == true)
      return false;

    visitSet.insert(courseNumber);

    for (int i : m[courseNumber]) {

      if (dfs(i, visitSet) == false) {
        return false;
      } else {
        s.insert(i);
      }
    }

    visitSet.erase(courseNumber);

    return true;
  }

  bool canFinish(int numCourses, vector<vector<int>> &prerequesites) {

    for (vector<int> x : prerequesites) {

      m[x[0]].push_back(x[1]);
    }

    for (int i{}; i < numCourses; i++) {
      set<int> vis;
      if (dfs(i, vis) == false)
        return false;
    }

    return true;
  }
};

int main() {

  Solution s;

  vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};

  bool ans = s.canFinish(2, prerequisites);

  cout << boolalpha << ans << endl;

  return 0;
}