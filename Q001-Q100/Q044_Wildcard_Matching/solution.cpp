#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  Solution() { this->count = 0; }

private:
  int count;

public:
  bool isMatch(string s, string p) {
    cout << "------------------" << endl;
    cout << "Now s is: " << s << endl;
    cout << "Now p is: " << p << endl;
    cout << "------------------" << endl;
    if (count++ > 10) {
      return false;
    }

    int s_len = s.size();
    int p_len = p.size();
    if (p.empty()) {
      return s.empty();
    }

    if (s.empty()) {
      if (p[0] == '*') {
        return isMatch(s, p.substr(1, p_len - 1));
      } else {
        return false;
      }
    }

    if (p[0] == '*') {
      return isMatch(s.substr(1, s_len - 1), p) ||
             isMatch(s, p.substr(1, p_len - 1));
    } else {
      return !s.empty() &&
             ((s[0] == p[0] || p[0] == '?') &&
              isMatch(s.substr(1, s_len - 1), p.substr(1, p_len - 1)));
    }
  }
};

int main() {
  string s, p;
  bool result;

  cout << "Enter the S:" << endl;
  cin >> s;
  cout << "Enter the p:" << endl;
  cin >> p;
  result = Solution().isMatch(s, p);
  cout << "Match result is: " << result << endl;
  return 0;
}