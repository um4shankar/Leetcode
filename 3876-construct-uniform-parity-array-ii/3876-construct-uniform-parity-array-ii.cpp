class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd_min = 1e9;
        int even_min = 1e9;
        for(int i=0; i<nums1.size(); ++i){
            if(nums1[i]%2!=0){
                odd_min = min(odd_min, nums1[i]);
            }
            else{
                even_min = min(even_min, nums1[i]);
            }
        }
        bool ans = false;
        if(odd_min < even_min || odd_min == 1e9 || even_min==1e9){
            ans = true;
        }
        return ans;
    }
};