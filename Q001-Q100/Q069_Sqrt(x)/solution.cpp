#include <math.h>
#include <iostream>

using namespace std;

class Solution {
   public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        } else if (x <= 3) {
            return 1;
        } else if (x < 9) {
            return 2;
        }

        int left = 3;
        int right = x / 2;
        if (right > 46340) {
            right = 46340;
        }

        int mid = (left + right) / 2;
        while ((mid * mid < x && (mid + 1) * (mid + 1) <= x) ||
               (mid * mid > x && (mid + 1) * (mid + 1) > x)) {
            if (mid * mid > x) {
                right = mid;
            } else {
                left = mid + 1;
            }

            mid = (left + right) / 2;
            if (mid == 46340) {
                break;
            }
        }

        return mid;
    }
};

int main(int argc, char** argv) {
    int x = 2147483647;
    Solution solu;
    cout << solu.mySqrt(x) << endl;
    return 0;
}
