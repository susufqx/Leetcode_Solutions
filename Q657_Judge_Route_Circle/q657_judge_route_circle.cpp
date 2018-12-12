class Solution {
public:
  bool judgeCircle(string moves) {
    int r_num = 0;
    int l_num = 0;
    int u_num = 0;
    int d_num = 0;

    int len = moves.length();

    for(int i=0;i<len;i++) {
      switch (moves[i]){
        case 'R':
          r_num ++;
        break;
        case 'L':
          l_num ++;
        break;
        case 'U':
          u_num ++;
        break;
        case 'D':
          d_num ++;
        break;
      }
    }
    if(r_num == l_num && u_num == d_num) {
      return true;
    } else {
      return false;
    }
  }
};
