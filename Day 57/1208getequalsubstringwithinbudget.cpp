class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0, r;
        for (r = 0; r < s.length(); r++) {
            maxCost -= abs(s[r] - t[r]);
            if (maxCost < 0)
                maxCost += abs(s[l] - t[l++]);
        }
        return r - l;
    }
};