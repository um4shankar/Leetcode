class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int maxi = 0;
        for (auto x : st) {
            int cnt = 1;
            if (st.count(x - 1) == 0) {
                while (st.count(x + 1) == 1) {
                    x++;
                    cnt++;
                }
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};