class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; ++i){
            int m = nums[i];
            int sum = 0;
            while(m>0){
                sum += m%10;
                m = m/10;
            }
            if(sum==i){
                return i;
            }
        }
        return -1;
    }
};