class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;

        while (i < t.size()) {
          if(t[i] != s[j]) {
            i++;
          } else {
            j++;
            i++;
          }
        }

        if(j<s.size()) return false;

        return true;

    }
};