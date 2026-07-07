class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int OFFSET = 10000;
        const int RANGE = 20001;

        vector<int> hsh(RANGE, 0);

        for (int x : nums) {
            hsh[x + OFFSET]++;
        }

        for (int i = RANGE - 1; i >= 0; --i) {
            if (hsh[i] != 0) {
                if (hsh[i] >= k) {
                    return i - OFFSET;
                }
                k -= hsh[i];
            }
        }

        return -1;
    }
};