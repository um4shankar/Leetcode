class Solution { 
public: 
    int countGoodRotations(vector<int>& nums) { 
        int n = nums.size(); 
        long sum = 0; 
        long cnt = 0; 
        for(int x : nums){
            sum += x;
        }
        long long sum1 = 0;
        for(int i = 0; i < n/2; ++i){
            sum1 += nums[i];
        }
        for(int i = 0; i < n; ++i) {
            if(sum1 > sum - sum1){
                cnt++;
            }
            sum1 += nums[(i + n/2) % n] - nums[i];
        }
        return cnt;
    } 
};