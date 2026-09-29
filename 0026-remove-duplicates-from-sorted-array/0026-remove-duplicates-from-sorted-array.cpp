class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(nums.begin(),nums.end());
        nums.clear();
        nums.push_back(temp[0]);
        int cnt = 1;
        for(int i=1; i<n; ++i){
            if(nums[i]!= nums[i-1]){
                nums.push_back(temp[i]);
                cnt++;
            }
        }
        return cnt;
    }
};