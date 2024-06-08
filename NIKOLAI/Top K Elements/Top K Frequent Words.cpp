#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> count;
    for (string& word : words) {
        count[word]++;
    }
    auto comp = [](pair<int, string>& a, pair<int, string>& b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    };
    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)> pq(comp);
    for (auto& it : count) {
        pq.push({it.second, it.first});
    }
    vector<string> result;
    for (int i = 0; i < k; i++) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}
