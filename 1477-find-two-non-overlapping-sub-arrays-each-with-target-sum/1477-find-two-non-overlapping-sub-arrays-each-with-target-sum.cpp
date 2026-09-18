class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int> mp;

        vector<int> best(n, 1e9);

        int sum = 0;
        int ans = 1e9;
        int minLen = 1e9;

        for (int i = 0; i < n; ++i) {
            sum += arr[i];

            if (i > 0)
                best[i] = best[i - 1];

            if (sum == target) {
                int len = i + 1;

                if (i > 0 && best[i - 1] != 1e9)
                    ans = min(ans, best[i - 1] + len);

                minLen = min(minLen, len);
                best[i] = min(best[i], minLen);
            }

            if (mp.find(sum - target) != mp.end()) {
                int j = mp[sum - target];
                int len = i - j;
                if (best[j] != 1e9)
                    ans = min(ans, best[j] + len);

                minLen = min(minLen, len);
                best[i] = min(best[i], minLen);
            }

            mp[sum] = i;
        }

        return ans == 1e9 ? -1 : ans;
    }
};