#include <cmath>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {

public:
  unordered_map<string, vector<pair<int, string>>> m;

  TimeMap() {}

  void set(string key, string value, int timestamp) {

    m[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {

    int l{};
    int r = m[key].size() - 1;
    int mid{};
    string res = "";
    while (r >= l) {

      mid = l + (r - l) / 2;

      if (m[key][mid].first == timestamp)
        return m[key][mid].second;

      if (timestamp >= m[key][mid].first) {
        res = m[key][mid].second;
        l = mid + 1;
      } else if (timestamp <= m[key][mid].first)
        r = mid - 1;
    }

    return res;
  }
};

int main() {
  TimeMap *t = new TimeMap();

  t->set("foo", "bar", 1);

  cout << t->get("foo", 1) << endl;
  cout << t->get("foo", 3) << endl;

  t->set("foo", "bar2", 4);
  cout << t->get("foo", 4) << endl;
  cout << t->get("foo", 5) << endl;

  return 0;
}