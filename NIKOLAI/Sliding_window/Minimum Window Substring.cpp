#include <string>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";
    
    unordered_map<char, int> t_map;
    for (char c : t) t_map[c]++;
    
    int left = 0, right = 0, required = t_map.size(), formed = 0;
    unordered_map<char, int> window_counts;
    int min_len = INT_MAX, start = 0;
    
    while (right < s.size()) {
        char c = s[right];
        window_counts[c]++;
        
        if (t_map.find(c) != t_map.end() && window_counts[c] == t_map[c]) {
            formed++;
        }
        
        while (left <= right && formed == required) {
            c = s[left];
            
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                start = left;
            }
            
            window_counts[c]--;
            if (t_map.find(c) != t_map.end() && window_counts[c] < t_map[c]) {
                formed--;
            }
            left++;
        }
        right++;
    }
    
    return min_len == INT_MAX ? "" : s.substr(start, min_len);
}
