#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> char_map;
    int left = 0, right = 0, max_len = 0;
    
    while (right < s.size()) {
        char_map[s[right]]++;
        
        while (char_map[s[right]] > 1) {
            char_map[s[left]]--;
            left++;
        }
        
        max_len = max(max_len, right - left + 1);
        right++;
    }
    
    return max_len;
}
