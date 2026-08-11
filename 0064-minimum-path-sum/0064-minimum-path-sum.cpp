class Solution {
public:
    vector<vector<int>> dp;
    int func(int x, int y, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (x >= n || y >= m)
            return 1e9;

        if (x == n - 1 && y == m - 1)
            return grid[x][y];

        if (dp[x][y] != -1)
            return dp[x][y];

        int down = func(x + 1, y, grid);
        int right = func(x, y + 1, grid);
        return dp[x][y] = grid[x][y] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.assign(n, vector<int>(m, -1));
        return func(0, 0, grid);
    }
};