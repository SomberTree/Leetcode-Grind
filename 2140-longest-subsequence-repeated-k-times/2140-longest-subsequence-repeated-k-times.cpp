class Solution {
    bool verify(string& cand, string& s, int k) {
        int cnt = 0;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (cand[j] == s[i])
                j++;
            if (j == cand.size()) {
                cnt++;
                j = 0;
            }
        }

        return cnt >= k;
    }

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string> q;
        q.push("");

        vector<int> char_cnt(26);
        vector<char> cand_chars;
        for (char c : s) {
            char_cnt[c - 'a']++;
        }

        for (char c='a'; c<='z'; c++) {
            if (char_cnt[c-'a'] >= k) {
                cand_chars.emplace_back(c);
            }
        }

        sort(cand_chars.begin(), cand_chars.end());

        string ans;
        while (!q.empty()) {
            string top = q.front();
            q.pop();
            for (char c : cand_chars) {
                top += c;
                if (verify(top, s, k)) {
                    ans = top;
                    q.push(top);
                }
                top.pop_back();
            }
        }

        return ans;
    }
};