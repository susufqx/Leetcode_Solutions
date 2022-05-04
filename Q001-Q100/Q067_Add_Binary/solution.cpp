#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string addBinary(string a, string b) {
        string res, tmp;
        int flag = 0;
        if (a.size() > b.size()) {
            res = a;
            tmp = b;
        } else {
            res = b;
            tmp = a;
        }

        for (int i = 0; i < res.size(); i++) {
            int x = 0;
            int tmpSize = tmp.size();
            if (tmpSize - i - 1 >= 0) {
                x = tmp[tmpSize - i - 1] - 48;
            }

            int y = res[res.size() - i - 1] - 48;
            int sum = x + y + flag;
            switch (sum) {
                case 0:
                    res[res.size() - 1 - i] = '0';
                    flag = 0;
                    break;
                case 1:
                    res[res.size() - 1 - i] = '1';
                    flag = 0;
                    break;
                case 2:
                    res[res.size() - 1 - i] = '0';
                    flag = 1;
                    break;
                case 3:
                    res[res.size() - 1 - i] = '1';
                    flag = 1;
                    break;

                default:
                    break;
            }
        }

        if (flag == 1) {
            res = '1' + res;
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string a = "11";
    string b = "1";
    Solution solu;
    cout << solu.addBinary(a, b) << endl;
    return 0;
}
