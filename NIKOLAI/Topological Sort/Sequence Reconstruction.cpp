#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    unordered_map<int, unordered_set<int>> adjList;
    unordered_map<int, int> inDegree;
    queue<int> q;
    
    for (const auto& seq : seqs) {
        for (int num : seq) {
            inDegree[num] = 0;
        }
    }
    
    for (const auto& seq : seqs) {
        for (int i = 0; i < seq.size() - 1; ++i) {
            if (adjList[seq[i]].insert(seq[i + 1]).second) {
                inDegree[seq[i + 1]]++;
            }
        }
    }
    
    for (const auto& pair : inDegree) {
        if (pair.second == 0) {
            q.push(pair.first);
        }
    }
    
    vector<int> order;
    while (!q.empty()) {
        if (q.size() != 1) {
            return false;
        }
        int num = q.front();
        q.pop();
        order.push_back(num);
        
        for (const auto& neighbor : adjList[num]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return order == org;
}
