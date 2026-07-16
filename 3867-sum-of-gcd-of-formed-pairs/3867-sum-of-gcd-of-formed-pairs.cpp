class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int mx = -1e9;
        int n = nums.size();
        for(int i=0; i<n; ++i){
            mx = max(mx, nums[i]);
            prefixGcd.push_back(gcd(mx, nums[i]));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int l = 0;
        int r = n-1;
        long long sum = 0;
        while(l<r){
            sum += gcd(prefixGcd[l],prefixGcd[r]);
            l++;
            r--;
        }
        return sum;
    }
};