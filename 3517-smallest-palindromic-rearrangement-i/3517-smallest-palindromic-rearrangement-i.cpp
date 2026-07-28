class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(), s.end());

        map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        string s1 = "";
        string s2 = "";
        string odd = "";

        for (auto &it : freq) {
            if (it.second % 2 != 0) {
                odd = string(1, it.first);
                it.second--;
            }

            while (it.second > 0) {
                s1 += it.first;
                s2 += it.first;
                it.second -= 2;
            }
        }

        reverse(s2.begin(), s2.end());
        return s1 + odd + s2;
    }
};