class Solution {
public:
    bool checkDivisibility(int n) {
        int digiSum = 0;
        int digiProd = 1;
        int x = n;
        while(x>0){
            int digi = x%10;
            digiSum += digi;
            digiProd *= digi;
            x = x/10;
        }
        bool ans = false;
        if(n % (digiSum + digiProd)==0){
            ans  =  true;
        }
        return ans;
    }
};