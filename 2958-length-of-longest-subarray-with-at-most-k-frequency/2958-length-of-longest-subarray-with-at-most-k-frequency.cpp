class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        int window = 0;
        int maxi = 0;

        for (int i = 0; i < n; ++i) {
            freq[nums[i]]++;
            if (freq[nums[i]] <= k) {
                window++;
                maxi = max(maxi, window);
            }
            else {
                while (freq[nums[i]] != freq[nums[i - window]]) {
                    freq[nums[i - window]]--;
                    window--;
                }
                if(freq[nums[i]] == freq[nums[i - window]]){
                    freq[nums[i - window]]--;
                }
            }
        }

        return maxi;
    }
};