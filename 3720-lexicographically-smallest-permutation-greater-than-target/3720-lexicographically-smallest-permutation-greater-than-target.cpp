class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};

        for (char ch : s) cnt[ch - 'a']++;
        for (char ch : target) cnt[ch - 'a']--;

        int bad = 0, mx = -1;

        for (int c = 0; c < 26; c++) {
            if (cnt[c] < 0) bad++;
            if (cnt[c] > 0) mx = c;
        }

        for (int i = target.size() - 1; i >= 0; i--) {
            int cur = target[i] - 'a';
            cnt[cur]++;

            if (cnt[cur] == 0) bad--;
            else if (cnt[cur] == 1) mx = max(mx, cur);

            if (bad > 0 || mx <= cur) continue;

            int next = cur + 1;
            while (cnt[next] == 0) next++;

            cnt[next]--;

            string ans = target.substr(0, i);
            ans += char('a' + next);

            for (int c = 0; c < 26; c++) {
                ans.append(cnt[c], char('a' + c));
            }

            return ans;
        }

        return "";
    }
};