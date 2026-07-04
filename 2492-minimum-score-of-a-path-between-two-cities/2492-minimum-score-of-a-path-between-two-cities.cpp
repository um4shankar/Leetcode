class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int N = roads.size();
        int mini = 1e9+10;
        for(auto it : roads){
            if(it[2] <mini){
                mini = it[2];
            }
        }
        return mini;
    }
};