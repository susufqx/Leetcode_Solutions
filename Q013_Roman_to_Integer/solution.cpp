/*
  Input number maximum is 3999
 */
# include <iostream>
# include <string>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    int len = s.size();
    int i = 0;
    int output = 0;

    while(s[i] == 'M'){
      output += 1000;
      i++;
    }
    this->dealRomanLetterToInteger(s, output, "MDC", i, 100);
    this->dealRomanLetterToInteger(s, output, "CLX", i, 10);
    this->dealRomanLetterToInteger(s, output, "XVI", i, 1);
    return output;
  }
private:
  void dealRomanLetterToInteger(string s, int& output, string symbol, int& i, int power){
    if(s[i] == symbol[1]){
      output += 5 * power;
      i++;
      while(s[i] == symbol[2]){
        output +=  power;
        i++;
      }
    }else if(s[i] == symbol[2]){
      output +=  power;
      i++;
      if(s[i] == symbol[1]){
        output = output + 3 * power;
        i++;
      }else if(s[i] == symbol[0]){
        output = output + 8 * power;
        i++;
      }else if(s[i] == symbol[2]){
        while(s[i] == symbol[2]){
          output +=  power;
          i++;
        }
      }
    }
  }
};

/* main function to test the code */
int main(int argc, char ** argv){
    string input;
    cout<<"Enter the input Roman number: "<<endl;
    cin>>input;
    cout<<"The Integer number is: "<<Solution().romanToInt(input)<<endl;
}
