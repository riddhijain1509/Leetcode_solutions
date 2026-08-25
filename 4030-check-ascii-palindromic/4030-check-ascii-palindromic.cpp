class Solution {
public:
    bool isPalindromic(string s) {
        int n = s.size();

        for (int i = 0; i < (n + 1) / 2; i++) {
            int leftChar = s[i];
            int rightChar = s[n - i - 1];

            for (int j = 0; j < 8; j++) {
                int left = (leftChar >> j) & 1;
                int right = (rightChar >> (7 - j)) & 1;

                if (left != right)
                    return false;
            }
        }

        return true;
    }
};