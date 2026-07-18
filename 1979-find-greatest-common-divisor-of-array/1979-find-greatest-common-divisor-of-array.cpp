class Solution {
public:
    int findGCD(vector<int>& nums) {
        int N = nums.size();
        int mini = 1e9;
        int maxi = -1e9;
        for(int i =0; i<N; ++i){
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        return gcd(maxi, mini);
    }
};