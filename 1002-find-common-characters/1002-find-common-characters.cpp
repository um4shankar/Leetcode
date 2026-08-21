class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> alpha(26,0);
        int n = words.size();
        for(int j=0; j<words[0].length(); ++j){
                alpha[words[0][j]-'a']++;
        }
        for(int i=1; i<n; ++i){
            vector<int> temp(26,0);
            for(int j=0; j<words[i].length(); ++j){
                temp[words[i][j]-'a']++;
            }
            for(int x=0; x<26; ++x){
                alpha[x] = min(alpha[x], temp[x]);
            }
        }

        vector<string> ans;
        for(int i=0; i<26; ++i){
            string p(1, i +'a');
            for(int j=0; j<alpha[i]; ++j){
                ans.push_back(p);
            }
        }
        return ans;
    }
};