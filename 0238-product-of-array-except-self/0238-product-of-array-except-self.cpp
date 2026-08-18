class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        vector<int> ans;
        int flag = 0;
        for(int i=0; i<n; ++i){
            if(nums[i]!=0)
            prod *= nums[i];
            else flag++;
        }
        for(int i=0; i<n; ++i){
            if(flag==1){
                if(nums[i]==0){
                    ans.push_back(prod);
                }
                else{
                    ans.push_back(0);
                }
            }
            else if(flag>1){
                ans.push_back(0);
            }
            else{
                ans.push_back(prod/nums[i]);
            }
        }
        return ans;
    }
};