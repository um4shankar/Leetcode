class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        long long n = nums.size();
        long long x = nums[0];
        long long sum = nums[0];
        for(int i=1; i<n; ++i){
            x = x^nums[i];
            sum += nums[i];
        }
        if(x == 0){
            if(sum == 0){
                return 0;
            }
            else{
                return n-1;
            }
        }
        else{
            return n;
        }
    }
};

// a ^ 0 = a
// a ^ a = 0
// a ^ b = b ^ a
// (a ^ b) ^ c = a ^ (b ^ c)