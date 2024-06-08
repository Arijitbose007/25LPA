#include <vector>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> subset;
    generateSubsets(0, nums, subset, result);
    return result;
}

void generateSubsets(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result) {
    result.push_back(subset);
    for (int i = index; i < nums.size(); i++) {
        subset.push_back(nums[i]);
        generateSubsets(i + 1, nums, subset, result);
        subset.pop_back();
    }
}
