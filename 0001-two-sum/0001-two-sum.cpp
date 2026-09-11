class Solution { 
public: 
    vector<int> twoSum(vector<int>& nums, int target) { 
        int n = nums.size(); 
        // sort(nums.begin(), nums.end()); 
        vector<pair<int, int>> nums1; 
        for(int i = 0; i < n; ++i) { 
            nums1.push_back({nums[i], i}); 
        } 
        sort(nums1.begin(), nums1.end()); 
        vector<int> ans; 
        int l = 0, r = n - 1; 
        while(l < r) { 
            if(nums1[l].first + nums1[r].first > target) { 
                r--; 
            } 
            else if(nums1[l].first + nums1[r].first < target) { 
                l++; 
            } 
            else { 
                ans.push_back(nums1[l].second); 
                ans.push_back(nums1[r].second); 
                break; 
            } 
        } 
        return ans; 
    } 
};