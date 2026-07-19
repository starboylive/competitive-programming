class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> vis(26), num(26);
        for (char ch : s) {
            num[ch - 'a']++;
        }

        string win;
        for (char ch : s) {
            if (!vis[ch - 'a']) {
                while (!win.empty() && win.back() > ch) {
                    if (num[win.back() - 'a'] > 0) {
                        vis[win.back() - 'a'] = 0;
                        win.pop_back();
                    } else {
                        break;
                    }
                }
                vis[ch - 'a'] = 1;
                win.push_back(ch);
            }
            num[ch - 'a'] -= 1;
        }
        return win;
    }
};