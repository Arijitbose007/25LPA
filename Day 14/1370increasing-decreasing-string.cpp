class Solution {
public:
    string sortString(string s) {
        std::array<int, 26> table{0};
        for (const char c : s) {
            ++table[c - 'a'];
        }

        std::string answer;
        while (answer.length() < s.length()) {
            for (int i = 0; i < table.size(); ++i) {
                if (table[i] > 0) {
                    answer += 'a' + i;
                    --table[i];
                }
            }
            for (int i = table.size() - 1; i >= 0; --i) {
                if (table[i] > 0) {
                    answer += 'a' + i;
                    --table[i];
                }
            }
        }
        return answer;
    }
};