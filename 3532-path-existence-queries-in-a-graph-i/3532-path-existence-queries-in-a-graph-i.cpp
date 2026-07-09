class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> diff;
        int digits = 1;
        diff.push_back(digits);

        for (int i = 1; i < n; i++) {
            if ((nums[i] - nums[i - 1]) <= maxDiff)
                digits++;
            diff.push_back(digits);
        }

        vector<bool> ans;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            if ((r - l) == (diff[r] - diff[l]))
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};