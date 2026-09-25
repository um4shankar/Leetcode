class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>> alpha(128);

        for(int i = 0; i < 128; i++)
            alpha[i] = {char(i), 0};

        for(char c : s)
            alpha[c].second++;

        sort(alpha.begin(), alpha.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string ans = "";

        for(auto &p : alpha) {
            for(int i = 0; i < p.second; i++)
                ans += p.first;
        }

        return ans;
    }
};