class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int N = intervals.size();
        int rem_int = N;
        vector<int> curr;
        curr.push_back(intervals[0][0]);
        curr.push_back(intervals[0][1]);
        for(int i = 1; i<N; ++i){
            if(curr[0] < intervals[i][0] && curr[1] >= intervals[i][1]){
                rem_int--;
            }
            else if(intervals[i][0] == curr[0]){
                if(intervals[i][1]>curr[1]){
                    rem_int--;
                    curr[0]= intervals[i][0];
                    curr[1]= intervals[i][1];
                }
                else{
                    rem_int--;
                } 
            }
            else if(curr[0] < intervals[i][0] && curr[1] < intervals[i][1]){
                curr[0]= intervals[i][0];
                curr[1]= intervals[i][1];
            }
        }
        return rem_int;
    }
};