class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> occupied;
        for (int i = 0; i < reservedSeats.size(); ++i) {
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];
            if (occupied.find(row) == occupied.end()) {
                occupied[row] = vector<int>(3, 0);
            }
            if (seat == 2 || seat == 3) {
                occupied[row][0] = 1;
            }
            else if (seat == 4 || seat == 5) {
                occupied[row][0] = 1;
                occupied[row][1] = 1;
            }
            else if (seat == 6 || seat == 7) {
                occupied[row][1] = 1;
                occupied[row][2] = 1;
            }
            else if (seat == 8 || seat == 9) {
                occupied[row][2] = 1;
            }
        }
        long long sum = 2LL * n;
        for (auto& row : occupied) {
            int sum1 = 0;
            for (int j = 0; j < 3; ++j) {
                sum1 += row.second[j];
            }
            if (sum1 == 0) {
                continue;
            }
            else if (sum1 == 3) {
                sum -= 2;
            }
            else {
                sum -= 1;
            }
        }
        return sum;
    }
};