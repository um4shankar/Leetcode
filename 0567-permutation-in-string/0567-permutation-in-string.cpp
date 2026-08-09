class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 > n2)
            return false;

        bool flag = false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (int i = 0; i < n1; ++i) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        for (int i = n1; i < n2; ++i) {
            if (freq1 == freq2) {
                flag = true;
                break;
            }
            else {
                freq2[s2[i - n1] - 'a']--;
                freq2[s2[i] - 'a']++;
            }
        }

        if (freq1 == freq2)
            flag = true;

        return flag;
    }
};