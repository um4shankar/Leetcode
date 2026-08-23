class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sumL = 0, sumR = 0;
        int cntL = 0, cntR = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?')
                cntL++;
            else
                sumL += num[i] - '0';
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?')
                cntR++;
            else
                sumR += num[i] - '0';
        }
        
        int diffCnt = cntL - cntR;
        int diffSum = sumL - sumR;
        if (diffCnt % 2 != 0)
            return true;
        return diffSum != -9 * (diffCnt / 2);
    }
};