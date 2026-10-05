class Solution { 
public: 
    int scoreOfParentheses(string s) { 
        int n = s.size(); 
        stack<int> st; 
        int sum = 0; 

        for(int i=0; i<n; ++i){ 
            if(s[i]=='('){ 
                st.push(sum); 
                sum = 0; 
            } 
            else{ 
                int prev = st.top(); 
                st.pop();

                if(s[i-1] == '(') 
                    sum = 1; 
                else 
                    sum = sum * 2;

                sum += prev;
            } 
        } 

        return sum; 
    } 
};