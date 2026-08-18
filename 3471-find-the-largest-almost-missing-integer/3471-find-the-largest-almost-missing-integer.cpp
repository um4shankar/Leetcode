class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> freq(51,0);
        int n = nums.size();
        for(int i=0; i<n; ++i){
            freq[nums[i]]++;
        }
        int ans = -1;
        if(k==1){
            for(int i=50; i>=0; --i){
                if(freq[i]==1){
                    ans = i;
                    break;
                }
            }
        }
        else if(k== nums.size()){
            for(int i=50; i>=0; --i){
                if(freq[i]!=0){
                    ans = i;
                    break;
                }
            }
        }
        else{
            int ans1 = -1, ans2= -1;
            if(freq[nums[n-1]]==1){
                ans1 = nums[n-1];
            }
            if(freq[nums[0]] == 1){
                ans2 = nums[0];
            }
            ans = max(ans1, ans2);
        }
        return ans;
    }
};