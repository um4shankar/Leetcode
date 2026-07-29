class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftSum;
        vector<int> rightSum;
        int n = nums.size();
        int sumL = 0;
        int sumR = 0;
        leftSum.push_back(sumL);
        rightSum.push_back(sumR);
        for(int i = 0; i<n; ++i){
            if(i>0){
                sumL += nums[i-1];
                leftSum.push_back(sumL);
                sumR += nums[n-i];
                rightSum.push_back(sumR);
            }
        }
        reverse(rightSum.begin(),rightSum.end());
        vector<int> ans;
        for(int i=0; i<n; ++i){
            ans.push_back(abs(leftSum[i]-rightSum[i]));
        }
        return ans;
    }
};