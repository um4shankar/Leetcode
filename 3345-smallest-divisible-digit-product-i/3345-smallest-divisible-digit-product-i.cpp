class Solution {
public:
    int smallestNumber(int n, int t) {
        vector<int> digitProduct;

        for (int i = n; i <= 100; ++i) {
            int multi = 1;
            int temp = i;

            while (temp > 0) {
                int dig = temp % 10;
                temp /= 10;
                multi *= dig;
            }

            digitProduct.push_back(multi);
        }

        int ans = 0;

        for (int i = 0; i < digitProduct.size(); ++i) {
            if (digitProduct[i] % t == 0) {
                ans = n + i;
                break;
            }
        }

        return ans;
    }
};