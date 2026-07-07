class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long rev = 0;
        long long num = n;
        long long posi = 1;
        while (num > 0) {
            int digit = num % 10;
            if(digit!=0){
                sum += digit;
                rev = rev + digit*posi;
                posi = posi*10;
            }
            num /= 10;  
        }
        return sum * rev;
    }
};