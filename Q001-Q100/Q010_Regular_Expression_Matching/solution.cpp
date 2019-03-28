#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int len_s = s.size();
		int len_p = p.size();

		if (p.empty()) {
			return s.empty();
		}
		if (len_p > 1 && p[1] == '*') {
			return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
		} else{
			return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
		}
	}
};

int main(int argc, char ** argv) {
	string s, p;
	bool result;

	cout<<"Enter the S:"<<endl;
	cin>>s;
	cout<<"Enter the p:"<<endl;
	cin>>p;
	result = Solution().isMatch(s, p);
	cout<<"Match result is: "<<result<<endl;
	return 0;
}