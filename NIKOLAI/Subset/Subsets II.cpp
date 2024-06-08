#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> subset;
    sort(nums.begin(), nums.end());
    generateSubsetsWithDup(0, nums, subset, result);
    return result;
}

void generateSubsetsWithDup(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result) {
    result.push_back(subset);
    for (int i = index; i < nums.size(); i++) {
        if (i > index && nums[i] == nums[i - 1]) continue;
        subset.push_back(nums[i]);
        generateSubsetsWithDup(i + 1, nums, subset, result);
        subset.pop_back();
    }
}
