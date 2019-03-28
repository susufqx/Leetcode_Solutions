#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private: map<string, string> numberToLetter;

public:
    vector<string> letterCombinations(string digits) {
      this->setMap(); // 首先执行该函数，对成员变量赋值
      vector<string> res;
      if (digits.empty()) return res; // digits is void
      string first_digit = digits.substr(0, 1);
      for (int i = 0; i < numberToLetter[first_digit].size(); i++) {
        res.push_back(numberToLetter[first_digit].substr(i, 1));
      }
      if (digits.size() == 1) return res; // digits size is 1
      return this->twoCombinations(letterCombinations(digits.substr(0, digits.size()-1)), numberToLetter[digits.substr(digits.size()-1, 1)]);
    }

private:
    void setMap() { // 给成员变量赋值，形成一个对应关系的map
      string le[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
      for (int i = 0; i < 8; i++) {
        this->numberToLetter[to_string(i+2)] = le[i];
      }
    }

    vector<string> twoCombinations(vector<string> s1, string s2) {
      vector<string> res;
      for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
          res.push_back(s1[i] + s2[j]);
        }
      }
      return res;
    }
};

int main(int argc, char ** argv) {
  vector<string> v = Solution().letterCombinations("234");
  cout<<"[";
  for (int i = 0; i < v.size(); i++) {
    if (i == v.size()-1) {
      cout<<v[i];
    } else{
      cout<<v[i]<<", ";
    }
  }
  cout<<endl;
  return 0;
}
