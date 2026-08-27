class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        string ans = "";

        for (char c : s)
            count[c - 'a']++;

        for (int i = 0; i < n; i++) {
            int p = target[i] - 'a';

            if (count[p] == 0) {
                for (int j = p + 1; j < 26; j++) {
                    if (count[j]) {
                        ans += char('a' + j);
                        count[j]--;

                        for (int k = 0; k < 26; k++)
                            while (count[k]--)
                                ans += char('a' + k);

                        return ans;
                    }
                }
                break;
            }

            ans += target[i];
            count[p]--;
        }

        for (int i = ans.size() - 1; i >= 0; i--) {
            int p = ans[i] - 'a';
            count[p]++;

            for (int j = p + 1; j < 26; j++) {
                if (count[j]) {
                    string res = ans.substr(0, i);
                    res += char('a' + j);
                    count[j]--;

                    for (int k = 0; k < 26; k++)
                        while (count[k]--)
                            res += char('a' + k);

                    return res;
                }
            }
        }

        return "";
    }
};