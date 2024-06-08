#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> combination;
    sort(candidates.begin(), candidates.end());
    findCombinationSum2(candidates, target, 0, combination, result);
    return result;
}

void findCombinationSum2(vector<int>& candidates, int target, int index, vector<int>& combination, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(combination);
        return;
    }
    for (int i = index; i < candidates.size(); i++) {
        if (i > index && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] > target) break;
        combination.push_back(candidates[i]);
        findCombinationSum2(candidates, target - candidates[i], i + 1, combination, result);
        combination.pop_back();
    }
}
