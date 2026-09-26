class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans  = "";
        string temp = "";
        int n = s.length();
        unordered_map<string, string> mp;
        int m = knowledge.size();
        for(int i=0; i<m; ++i){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        bool check = false;
        for(int i=0; i<n; ++i){
            if(check == false){
                if(s[i]== '('){
                    check = true;
                }
                else{
                    ans += s[i];
                }
            }
            else{
                if(s[i]== ')'){
                    check = false;
                    if(mp.find(temp) != mp.end()){
                        ans += mp[temp];
                    }
                    else{
                        ans += '?';
                    }
                    temp = "";
                }
                else{
                    temp += s[i];
                }
            }
        }
        return ans;
    }
};