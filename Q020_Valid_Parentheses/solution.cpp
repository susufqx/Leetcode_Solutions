#include <iostream>
#include <string>
#include <stack>

using namespace std;
/*
'{}' '[]' '(())' like these are rigth, '{(})' like this is wrong
*/
class Solution {
public:
  bool isValid(string s) {
    int i;
    int len = s.length(); // get the input length
    stack <char> stk; // create a stack

    for (i = 0; i < len; i++) {
      if (s[i] != ')' && s[i] != ']' && s[i] != '}') {
        stk.push(s[i]);
      } else {
        if (stk.size() == 0) {
          return false;
        }
        char top_char = stk.top();
        switch (s[i]) {
          case ')':
            if (top_char == '(') {
              stk.pop();
            } else {
              return false;
            }
            break;
          case ']':
            if (top_char == '[') {
              stk.pop();
            } else {
              return false;
            }
            break;
          case '}':
            if (top_char == '{') {
              stk.pop();
            } else {
              return false;
            }
            break;
        }
      }
    }

    return (stk.size() == 0);
  }
};

int main(int argc, char ** argv) {
  Solution solu;
  string s;
  cout<<"Please enter the parentheses:"<<endl;
  cin>>s;
  bool res = solu.isValid(s);
  cout<<res<<endl;
  return 0;
}
