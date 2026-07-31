class Solution {
public:
    int minimumPushes(string word) {
        int n =  word.length();
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }
        sort(freq.begin(),freq.end(), greater<int>());
        int alpha = 1;
        int sum = 0;
        for(auto it: freq){
            if(alpha<9){
                if(it != 0){
                    sum += 1*it;
                    alpha++;
                }
            }
            else if(alpha >= 9 && alpha <17){
                if(it != 0){
                    sum += 2*it;
                    alpha++;
                }
            }
            else if(alpha >= 17 && alpha < 25){
                if(it != 0){
                    sum += 3*it;
                    alpha++;
                }
            }
            else{
                if(it != 0){
                    sum += 4*it;
                    alpha++;
                }
            } 
        }
        return sum;
    }
};