class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        vector<int> index;
        for(int i=0; i<n; ++i){
            if(s[i]=='1'){
                index.push_back(i);
            }
        }
        int m = index.size();
        int x = 0;
        int start = 0;
        int end = k-1;
        int mini = 1e9;
        vector<string> ans;
        while(end < m){
            ans.push_back(s.substr(index[start], index[end]-index[start]+1));
            mini = min(mini, index[end]-index[start]+1);
            start++;
            end++;
        }
        string str = "";
        if(ans.empty()){
            return str;
        }
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); ++i){
            if(ans[i].length() == mini){
                return ans[i];
            }
        }
        return str;
    }
};