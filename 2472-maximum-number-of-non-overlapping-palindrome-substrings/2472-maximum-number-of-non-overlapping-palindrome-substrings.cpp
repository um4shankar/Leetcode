class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<pair<int, int>> pal;

        for (int center = 0; center < n; center++) {
            int l = center;
            int r = center;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    pal.push_back({l, r});
                }
                l--;
                r++;
            }

            l = center;
            r = center + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    pal.push_back({l, r});
                }
                l--;
                r++;
            }
        }

        sort(pal.begin(), pal.end(), [](auto a, auto b) {
            return a.second < b.second;
        });

        int cnt = 0;
        int last = -1;

        for (auto p : pal) {
            if (p.first > last) {
                cnt++;
                last = p.second;
            }
        }

        return cnt;
    }
};