#include <cctype>
#include <iostream>

using namespace std;

string licenseKeyFormatting(string s, int k) {

  int num = k;

  string ans;

  for (char x : s) {

    if (x != '-')
      ans.push_back(toupper(x));
  }

  string ans2;

  for (int i = ans.size() - 1; i >= 0; i--) {

    if (num == 0) {
      num = k;
      ans2.push_back('-');
    }
    ans2.push_back(ans[i]);

    num--;
  }
  string ans3;

  for (int i = ans2.size() - 1; i >= 0; i--) {

    ans3.push_back(ans2[i]);
  }

  return ans3;
}

int main() {
  string s = "2-5g-3-J";

  string ans = licenseKeyFormatting(s, 2);

  cout << ans << endl;

  return 0;
}