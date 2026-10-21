class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        string str = s;
        sort(str.begin(), str.end());

        if (str == s) {
            return 0;
        }

        if (n == 2) {
            return -1;
        }

        if (s[0] == str[0] || s[n-1] == str[n-1]) {
            return 1;
        }

        char mn = str[0], mx = str[n-1];
        int cntMin = count(s.begin(), s.end(), mn);
        int cntMax = count(s.begin(), s.end(), mx);

        if (s[0] == mx && s[n-1] == mn && cntMax == 1 && cntMin == 1) {
            return 3;
        }

        return 2;
    }
};

