#include <string>
#include <vector>

using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    
    vector<int> s1_count(26, 0), s2_count(26, 0);
    for (int i = 0; i < s1.size(); i++) {
        s1_count[s1[i] - 'a']++;
        s2_count[s2[i] - 'a']++;
    }
    
    int matches = 0;
    for (int i = 0; i < 26; i++) {
        if (s1_count[i] == s2_count[i]) matches++;
    }
    
    for (int i = s1.size(); i < s2.size(); i++) {
        if (matches == 26) return true;
        
        int r = s2[i] - 'a', l = s2[i - s1.size()] - 'a';
        s2_count[r]++;
        if (s2_count[r] == s1_count[r]) {
            matches++;
        } else if (s2_count[r] == s1_count[r] + 1) {
            matches--;
        }
        
        s2_count[l]--;
        if (s2_count[l] == s1_count[l]) {
            matches++;
        } else if (s2_count[l] == s1_count[l] - 1) {
            matches--;
        }
    }
    
    return matches == 26;
}
