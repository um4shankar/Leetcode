class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int flag = 0;
        int cnt = 0;
        for(int i=n-1; i>=0; --i){
            if(flag == 0 && s[i]!= ' '){
                cnt++;
                flag = 1;
            }
            else if(flag == 1 && s[i]!= ' '){
                cnt++;
            }
            else if(flag == 1 && s[i]== ' '){
                break;
            }
        }
        return cnt;
    }
};