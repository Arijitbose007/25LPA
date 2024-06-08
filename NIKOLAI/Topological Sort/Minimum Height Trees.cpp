#include <vector>
#include <unordered_set>

using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};
    vector<unordered_set<int>> adjList(n);
    vector<int> leaves;
    
    for (const auto& edge : edges) {
        adjList[edge[0]].insert(edge[1]);
        adjList[edge[1]].insert(edge[0]);
    }
    
    for (int i = 0; i < n; ++i) {
        if (adjList[i].size() == 1) {
            leaves.push_back(i);
        }
    }
    
    while (n > 2) {
        n -= leaves.size();
        vector<int> newLeaves;
        for (int leaf : leaves) {
            int neighbor = *adjList[leaf].begin();
            adjList[neighbor].erase(leaf);
            if (adjList[neighbor].size() == 1) {
                newLeaves.push_back(neighbor);
            }
        }
        leaves = newLeaves;
    }
    
    return leaves;
}
