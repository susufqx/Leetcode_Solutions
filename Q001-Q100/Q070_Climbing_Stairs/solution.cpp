#include <iostream>

using namespace std;

class Solution {
   public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }

        // int* res = (int*)malloc(sizeof(int) * n);
        int res[3] = {1, 2, 0};
        // res[0] = 1;  // n=1
        // res[1] = 2;  // n=2
        for (int i = 2; i < n; i++) {
            // res[i] = res[i - 2] + res[i - 1];
            res[2] = res[0] + res[1];
            res[0] = res[1];
            res[1] = res[2];
        }

        // return res[n - 1];
        return res[2];
    }
};

int main(int argc, char** argv) {
    Solution solu;
    cout << solu.climbStairs(3) << endl;
    return 0;
}