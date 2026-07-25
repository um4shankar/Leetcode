class Solution {
public:
    int maxProduct(int n) {
        vector<int> digit;
        while(n){
            int dig = n%10;
            n = n/10;
            digit.push_back(dig);
        }
        sort(digit.begin(),digit.end(), greater<int>());
        return digit[0]*digit[1];
    }
};