int lengthOfLongestSubstring(char* s) {
    if (s == NULL) {
        return 0;
    } else {
        int i = 0, j;
        int left=0, res=0;
        int c[256] = {0};

        for (j = 0; j < 256; j++) {
            c[j] = -1;
        }

        while(s[i] != '\0') {
          if (c[s[i]] != -1 && c[s[i]] >= left) {
            left = c[s[i]] + 1;
          }
          int l = i - left + 1;
          if (l > res) {
            res = l;
          }
          c[s[i]] = i;
          i++;
        }
        return res;
    }
}
