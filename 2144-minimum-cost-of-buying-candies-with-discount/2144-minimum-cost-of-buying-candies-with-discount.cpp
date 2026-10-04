class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int sum = 0;
        int cnt = 0;
        int  n = cost.size();
        for(int i=0; i<n; i++){
            if(cnt==2){
                cnt=0;
            }
            else{
                sum += cost[i];
                cnt++;
            }
        }
        return sum;
    }
};