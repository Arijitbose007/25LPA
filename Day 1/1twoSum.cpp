class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> devin;
        for(int i = 0 ; i < nums.size() ; i++){
            int pivot = target - nums[i];
            if(devin.count(pivot)){
                return {devin[pivot],i};
            }   
            devin[nums[i]] = i;
        }
        return {};
    }
};