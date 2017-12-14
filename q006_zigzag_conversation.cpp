#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    string res = s;
    int len = s.length();
    int k = 0;

    if(len == 0 || numRows == 1) return s;

    for(int i=0;i<numRows;i++) {
      int m = 0;
      int n;

      while(1) {
        if(i == 0 || i == numRows-1) {
          n = i + m * (2*numRows - 2);
        } else if(m % 2 == 0){
          n = i + m / 2 * (2*numRows - 2);
        } else {
          n = i + (m + 1) / 2 * (2*numRows - 2) - 2 * i;
        }
        if(n >= len) break;
        res[k] = s[n];
        m++;
        k++;
      }
    }
    return res;
  }
};

/* main function is the test code */
int main(int argc, char ** argv) {
  Solution solu;
  string test_s = "PAYPALISHIRING";
  cout<<solu.convert(test_s, 3)<<endl;
  return 0;
}
