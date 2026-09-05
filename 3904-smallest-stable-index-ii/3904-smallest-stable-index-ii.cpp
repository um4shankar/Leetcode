class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans = -1;
        int n =  nums.size();
        int maxi = -1e9;
        int mini =  1e9;
        vector<int> prefMax;
        vector<int> prefMin(n,0);
        for(int i=n-1; i>=0; --i){
            mini = min(mini, nums[i]);
            prefMin[i] = mini;
        }
        for(int i=0; i<n; ++i){
            maxi = max(maxi, nums[i]);
            if(maxi-prefMin[i]<=k){
                ans = i;
                break;
            } 
        }
        return ans;
    }
};