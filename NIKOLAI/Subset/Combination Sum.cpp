#include <vector>

using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> combination;
    findCombinationSum(candidates, target, 0, combination, result);
    return result;
}

void findCombinationSum(vector<int>& candidates, int target, int index, vector<int>& combination, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(combination);
        return;
    }
    for (int i = index; i < candidates.size(); i++) {
        if (candidates[i] > target) continue;
        combination.push_back(candidates[i]);
        findCombinationSum(candidates, target - candidates[i], i, combination, result);
        combination.pop_back();
    }
}
