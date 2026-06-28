class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        arr[0] = 1;
        int maxi = arr[0];
        for(int i=1; i<n; ++i){
            if(abs(arr[i] - arr[i - 1]) <= 1){
                maxi = arr[i];
            }
            else{
                arr[i] = maxi+1;
                maxi = arr[i];
            }
        }
        return maxi;
    }
};