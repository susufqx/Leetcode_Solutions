#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    int rem;
    int iToR[4];
    int div = 1000;
    string res = "";

    if(num >= 4000){
      string res = "Wrong, please input the number between 1 to 3999";
      return res;
    }
    for(int i=0;i<4;i++){
      iToR[i] = num / div * div;
      num %= div;
      div /= 10;
      if(iToR[i] != 0){
        res += this->setUnitRoman(iToR[i]);
      }
    }
    return res;
  }
private:
  string setUnitRoman(int num) {
    string romanStr[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int romanInt[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

    for(int i=0;i<13;i++){
      if(num == romanInt[i]){
        return romanStr[i];
      }
    }
    if(num>1 && num<4){
      return this->resRoman(num, "I");
    }else if(num>5 && num<9){
      return "V" + this->resRoman(num-5, "I");
    }else if(num>10 && num<40){
      return this->resRoman(num/10, "X");
    }else if(num>50 && num<90){
      return "L" + this->resRoman(num/10-5, "X");
    }else if(num>100 && num<400){
      return this->resRoman(num/100, "C");
    }else if(num>500 && num<900){
      return "D" + this->resRoman(num/100-5, "C");
    }else if(num>1000){
      return this->resRoman(num/1000, "M");
    }
    return "";
  }

  string resRoman(int n, string s){
    string res = "";
    for(int i=0;i<n;i++){
      res += s;
    }
    return res;
  }
};

int main(int argc, char ** argv){
  int input;
  cout<<"Please enter the input integer number: "<<endl;
  cin>>input;
  cout<<Solution().intToRoman(input)<<endl;
  return 0;
}
