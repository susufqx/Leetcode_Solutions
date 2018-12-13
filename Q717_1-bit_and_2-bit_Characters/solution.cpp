#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isOneBitCharacter(vector<int>& bits) {
    int n = bits.size();
    int i = 0;
    while(i < n-1) {
      if(bits[i] == 1) {
        i += 2;
      } else {
        i += 1;
      }
    }
    if(i == n) {
      return false;
    } else {
      return true;
    }
  }
};

int main(int argc, char ** argv) {
  // test code here
  vector<int> v1;
  vector<int> v2;
  v1.push_back(1);
  v1.push_back(1);
  v1.push_back(1);
  v1.push_back(0);
  v2.push_back(1);
  v2.push_back(0);
  v2.push_back(0);
  Solution solu;
  cout<<"Input is [1,1,1,0], result is "<<solu.isOneBitCharacter(v1)<<endl;
  cout<<"Input is [1,0,0], result is "<<solu.isOneBitCharacter(v2)<<endl;
  return 0;
}
