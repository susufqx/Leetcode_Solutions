class Solution {
public:
    int hammingDistance(int x, int y) {
        int i = 0, j = 0;
        int ax[32] = {0};
        int bx[32] = {0};
        int res = 0;

        if(x == y) {
            return 0;
        }
        if(x < y) {
            return hammingDistance(y, x);
        }
        while( x / 2 >= 1) {
            ax[i] = x % 2;
            x = x / 2;
            i++;
        }
        ax[i] = x % 2;
        while( y / 2 >= 1) {
            bx[j] = y % 2;
            y = y / 2;
            j++;
        }
        bx[j] = y % 2;
        //here j <= i, because y <= x
        for(int k=0;k<=i;k++) {
            if(ax[k] != bx[k]) {
                res += 1;
            }
        }
        return res;
    }
};
