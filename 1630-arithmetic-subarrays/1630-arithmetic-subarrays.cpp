class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> ans(m);
        for(int i = 0; i < m; ++i) {
            vector<int> sub_arr(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(sub_arr.begin(), sub_arr.end());
            int temp = sub_arr[1] - sub_arr[0];
            ans[i] = true;
            for(int j = 1; j < sub_arr.size(); ++j) {
                if(sub_arr[j] - sub_arr[j - 1] != temp) {
                    ans[i] = false;
                    break;
                }
            }
            
        }
        return ans;
    }
};