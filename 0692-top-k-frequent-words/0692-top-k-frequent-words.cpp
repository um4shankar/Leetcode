class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        sort(words.begin(), words.end());

        vector<pair<string, int>> freq;
        string prev = words[0];
        int cnt = 1;

        for (int i = 1; i < n; ++i) {
            string curr = words[i];
            if (prev == curr) {
                cnt++;
            } else {
                freq.push_back({prev, cnt});
                prev = words[i];
                cnt = 1;
            }
        }

        // Missing last word
        freq.push_back({prev, cnt});

        sort(freq.begin(), freq.end(), [](const auto& a, const auto& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });

        vector<string> ans;
        int m = 0;

        for (auto it : freq) {
            if (m >= k) break;
            ans.push_back(it.first);
            m++;
        }

        return ans;
    }
};