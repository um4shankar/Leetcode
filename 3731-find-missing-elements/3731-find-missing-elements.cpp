class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = nums[0];
        int r = nums[n-1];
        vector<int>ans;
        int idx =0;
        for(int i=l; i<=r; i++){
            if(i != nums[idx]){
                ans.push_back(i);
            }
            else{
                idx++;
            }
        }
        return ans;
    }
};