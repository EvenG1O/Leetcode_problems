#include <cctype>
#include <iostream>
#include <string>

using namespace std;

string maskPII(string s) {

  string ans;

  if (isalpha(static_cast<unsigned char>(s[0]))) {

    for (char &c : s)
      c = tolower(static_cast<unsigned char>(c));

    size_t pos = s.find('@');

    string name = s.substr(0, pos);
    string domain = s.substr(pos + 1);

    name = name[0] + string("*****") + name.back();

    return name + '@' + domain;
  }

  else {

    string digits;
    for (char c : s) {
      if (isdigit(static_cast<unsigned char>(c))) {
        digits += c;
      }
    }

    string last4 = digits.substr(digits.size() - 4);
    int countryCodeLen = (int)digits.size() - 10;

    if (countryCodeLen <= 0) {
      return "***-***-" + last4;
    }

    string prefix = "+";
    prefix.append(countryCodeLen, '*');
    return prefix + "-***-***-" + last4;
  }
}

int main() {

  cout << maskPII("(234)567-890") << endl;
  cout << maskPII("LeetCode@LeetCode.com") << endl;

  return 0;
}