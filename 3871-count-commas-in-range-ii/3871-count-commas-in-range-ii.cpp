class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long x=1000;
        while(n >= x){
            ans += (n-x+1);
            x *= 1000;
        }
        return ans;
    }
};