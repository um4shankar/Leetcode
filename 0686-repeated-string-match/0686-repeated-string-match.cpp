class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int Na = a.length();
        int Nb = b.length();
        int N = (Nb + Na - 1) / Na;
        string s="";
        for(int i = 0; i<N; ++i){
            s += a;
        }
        if(s.find(b) != string::npos){
            return N;
        }
        else{
            s += a;
        }
        if(s.find(b) != string::npos){
            return N+1;
        }
        else{
            return -1;
        }
    }
};