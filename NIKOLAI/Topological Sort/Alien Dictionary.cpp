#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> adjList;
    unordered_map<char, int> inDegree;
    queue<char> q;
    string result;
    
    for (const auto& word : words) {
        for (const auto& c : word) {
            inDegree[c] = 0;
        }
    }
    
    for (int i = 0; i < words.size() - 1; ++i) {
        string word1 = words[i];
        string word2 = words[i + 1];
        if (word1.size() > word2.size() && word1.substr(0, word2.size()) == word2) {
            return "";
        }
        for (int j = 0; j < min(word1.size(), word2.size()); ++j) {
            if (word1[j] != word2[j]) {
                if (adjList[word1[j]].insert(word2[j]).second) {
                    inDegree[word2[j]]++;
                }
                break;
            }
        }
    }
    
    for (const auto& pair : inDegree) {
        if (pair.second == 0) {
            q.push(pair.first);
        }
    }
    
    while (!q.empty()) {
        char c = q.front();
        q.pop();
        result += c;
        
        for (const auto& neighbor : adjList[c]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return result.size() == inDegree.size() ? result : "";
}
