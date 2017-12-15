#include <iostream>

using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    int a = 0;
    int b = x;
    while(b > 0) {
      a = a * 10 + b % 10;
      b = b / 10;
    }
    return (a == x)? true : false;
  }
};

int main(int argc, char ** argv) {
  int x = 121;
  Solution solu;
  cout<<solu.isPalindrome(x)<<endl;
  return 0;
}
