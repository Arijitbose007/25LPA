class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxCurrent = nums[0];
        int maxGlobal = nums[0]; 

        for(int i = 1; i < nums.size(); i++) {
        
       // Start loop from index 1
            maxCurrent = max(nums[i], nums[i] + maxCurrent);
            maxGlobal = max(maxGlobal, maxCurrent); 
        }
        
        return maxGlobal;
    }
};
