class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            s += s[0];
            s.erase(0, 1);
            int cnt = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (s[i] == s[i + 1]) {
                    cnt++;
                }
            }

            if (cnt == k) {
                ans++;
            }
        }

        return ans;
    }
};