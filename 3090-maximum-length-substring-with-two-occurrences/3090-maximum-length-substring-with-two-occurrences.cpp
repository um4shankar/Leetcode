class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int> freq(26,0);
        int window = 0;
        int maxi = 0;
        for(int i=0; i<n; ++i){
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']<=2){
                window++;
                maxi = max(window, maxi);
            }
            else{
                while(s[i]!=s[i-window]){
                    freq[s[i-window]-'a']--;
                    window--;
                }
                freq[s[i]-'a']--;
            }
            maxi = max(window, maxi);
        }
        return maxi;
    }
};