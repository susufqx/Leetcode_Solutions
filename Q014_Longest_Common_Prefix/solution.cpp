#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      if (strs.empty()) {
        return "";
      }

      int len_vector = strs.size();
      int min_size = strs[0].length();
      int str_length, i;
      string common_str = "";

      for (i = 1; i < len_vector; i++) {
        str_length = strs[i].length();
        if (str_length < min_size) {
          min_size = str_length;
        }
      }
      for (i = 0; i < min_size; i++) {
        for (int j = 1; j < len_vector; j++) {
          if (strs[j-1].substr(0, i+1) != strs[j].substr(0, i+1)) {
            return common_str;
          }
        }
        common_str += strs[0][i];
      }
      return common_str;
    }
};

int main(int argc, char ** argv) {
  vector<string> s = {};
  cout<<Solution().longestCommonPrefix(s)<<endl;
}
