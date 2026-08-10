class Solution {
public:
    int maxJump(vector<int>& stones) {
        int ans = 0;

        for (int i = 2; i < stones.size(); i++) {
            ans = max(ans, stones[i] - stones[i - 2]);
        }

        return max(ans, stones[1] - stones[0]);
    }
};   //Imp* The cost of a path is the maximum length of a jump among all jumps in the path.