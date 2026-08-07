class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";

        for (char ch : s) {
            if (ch >= 'a' && ch <= 'z') {
                ans += ch;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                ans += (ch - 'A' + 'a');
            }
            else if (ch >= '0' && ch <= '9') {
                ans += ch;
            }
        }

        int l = 0;
        int r = ans.length() - 1;

        while (l <= r) {
            if (ans[l] != ans[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};