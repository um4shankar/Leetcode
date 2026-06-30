class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int target = 9;
        int sum = 0;
        vector<int> arr;
        for(int i =0; i<n; ++i){
            if(s[i]=='a'){
                arr.push_back(1); // 1 for a
            }
            else if(s[i]=='b'){
                arr.push_back(3); // 3 for b
            }
            else{
                arr.push_back(5);   // 5 for c
            }
        }
        bool hit = false;
        int cnt = 0;
        for(int i=0; i<n; ++i){
            sum = arr[i];
            hit = false;
            for(int j=i; j<n; ++j){
                    if(sum!=arr[j]){
                    if(sum == 1 || sum == 3 || sum == 5){
                        sum += arr[j];
                    }
                    else if(sum + arr[j] == target){
                        sum += arr[j];
                        hit =  true;
                        cnt += n-j;
                        break;
                    }
                   }
            }
        }
        return cnt;
    }
};