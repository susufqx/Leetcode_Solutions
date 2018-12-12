#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int len = s.length();
    int *a = new int[len];
    int *b = new int[len];
    int k = 0;
    int res=0, left=0;
    int j;

    if(s.empty()) {
      return "";
    }
    if(s.length() == 1) {
      return s;
    }
    for(int i=0;i<len;i++) {
      if(s[i] == s[i+1]) {
        b[k] = 2;
        if(i>=1) {
          for(j=i-1;j>=0;j--){
            if(s[j] == s[2*i+1-j]) {
              b[k] += 2;
            }else{
              break;
            }
          }
        } else {
          j = -1;
        }
        if(res < b[k]) {
          res = b[k];
          left = j+1;
        }
      }

      a[k] = 1;
      if(i>=1){
        for(j=i-1;j>=0;j--) {
          if(s[j] == s[2*i-j]) {
            a[k] += 2;
          }else{
            break;
          }
        }
      } else {
        j = -1;
      }

      if(res < a[k]) {
        res = a[k];
        left = j+1;
      }
      k++;
    }
    return s.substr(left, res);
  }
};

int main(int argc, char ** argv) {
  string a = "ccbbaa";
  Solution solu;
  cout<<solu.longestPalindrome(a)<<endl;
  return 0;
}
