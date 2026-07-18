class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string before, ys, xs;

        for (char c : s) {
            if (c == y)
                ys += c;
            else if (c == x)
                xs += c;
            else
                before += c;
        }

        return before + ys + xs;
    }
};