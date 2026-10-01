class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            int x;

            if (s[i] == '(') x = 1;
            else if (s[i] == ')') x = -1;
            else if (s[i] == '{') x = 2;
            else if (s[i] == '}') x = -2;
            else if (s[i] == '[') x = 3;
            else x = -3;

            if (!st.empty() && x + st.top() == 0 && st.top()>x)
                st.pop();
            else
                st.push(x);
        }

        return st.empty();
    }
};