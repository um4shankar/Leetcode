class Solution {
public:
    int findGCD(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        return gcd(nums[0], nums[N-1]);
        // int mini = 1e9;
        // int maxi = -1e9;
        // for(int i =0; i<N; ++i){
        //     mini = min(mini, nums[i]);
        //     maxi = max(maxi, nums[i]);
        // }
        // return gcd(maxi, mini);
    }
};