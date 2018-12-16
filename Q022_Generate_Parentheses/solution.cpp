#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> output;
      this->generateP(n, n, "", output);
      return output;
    }

private:
    void generateP(int left, int right, string tempStr, vector<string>& res) {
      if (left > right) return;
      if (left == 0 && right == 0) {
        res.push_back(tempStr);
      } else {
        if (left > 0) generateP(left - 1, right, tempStr + ('('), res);
        if (right > 0) generateP(left, right - 1, tempStr + (')'), res);
      }
    }
};

int main(int argc, char ** argv) {
  int n;
  cout<<"Please enter the Number of pairs of parentheses: "<<endl;
  cin>>n;
  vector<string> v = Solution().generateParenthesis(n);
  cout<<"["<<endl;
  for (int i = 0; i < v.size(); i++) {
    if (i != v.size() - 1) {
      cout<<"  "<<v[i]<<","<<endl;
    } else {
      cout<<"  "<<v[i]<<endl;
    }
  }
  cout<<"]"<<endl;
  return 0;
}
