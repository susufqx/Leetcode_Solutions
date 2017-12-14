#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    int len = str.length();
    int i=0;
    int res=0;
    int flag=1;

    if(str.length() == 0) return 0; // null or empty
    while (i<len && str[i] == ' ') {
        i++;
    } // to remove the spaces
    if(str[i] == '+' || str[i] == '-') {
        flag = (str[i++] == '+') ? 1 : -1;
    } // to judge the number negative or positive
    while(i<len && str[i] >= '0' && str[i] <= '9') {
        if(res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0') > 7)) {
            return (flag == 1) ? INT_MAX : INT_MIN;
        }
    }
    return res * flag;
  }
};

int main(int argc, char ** argv) {
  string test_s = "2147483648";
  Solution solu;
  cout<<solu.myAtoi(test_s)<<endl;
  return 0;
}
