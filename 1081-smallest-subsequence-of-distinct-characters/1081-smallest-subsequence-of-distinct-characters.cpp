class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> inStack(26, false);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        stack<char> st;

        for (char ch : s) {
            freq[ch - 'a']--;

            if (inStack[ch - 'a'])
                continue;

            while (!st.empty() &&
                   st.top() > ch &&
                   freq[st.top() - 'a'] > 0) {

                inStack[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            inStack[ch - 'a'] = true;
        }

        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};