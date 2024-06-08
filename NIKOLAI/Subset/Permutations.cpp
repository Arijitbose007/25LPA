#include <vector>

using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> permutation;
    vector<bool> visited(nums.size(), false);
    generatePermutations(nums, permutation, visited, result);
    return result;
}

void generatePermutations(vector<int>& nums, vector<int>& permutation, vector<bool>& visited, vector<vector<int>>& result) {
    if (permutation.size() == nums.size()) {
        result.push_back(permutation);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (visited[i]) continue;
        visited[i] = true;
        permutation.push_back(nums[i]);
        generatePermutations(nums, permutation, visited, result);
        permutation.pop_back();
        visited[i] = false;
    }
}
