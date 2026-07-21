class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s = "1" + s + "1";

        int totalOnes = 0;
        vector<pair<char,int>> groups;

        for (int i = 0; i < s.size();) {
            char ch = s[i];
            int len = 0;

            while (i < s.size() && s[i] == ch) {
                len++;
                i++;
            }

            groups.push_back({ch, len});

            if (ch == '1')
                totalOnes += len;
        }

        int ans = totalOnes - 2;

        for (int i = 1; i + 1 < groups.size(); i++) {

            if (groups[i].first == '1' &&
                groups[i - 1].first == '0' &&
                groups[i + 1].first == '0') {

                int curr = totalOnes + groups[i - 1].second + groups[i + 1].second - 2;

                ans = max(ans, curr);
            }
        }

        return ans;
    }
};