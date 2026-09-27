class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(n + 1);
        steps[n] = 1;
        steps[n - 1] = 1;
        while(n - 2 >= 0) {
            steps[n - 2] = steps[n - 1] + steps[n];
            n--;
        }
        return steps[0];
    }
};