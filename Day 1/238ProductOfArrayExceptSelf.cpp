class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalMult = 1;
        int zeroCount = 0; // Count the number of zeros in nums
        vector<int> output(nums.size(), 0); // Initialize output vector with zeros
        
        // Calculate the total product of all non-zero elements
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                totalMult *= nums[i];
            } else {
                zeroCount++; // Increment zeroCount if nums[i] is zero
            }
        }
        
        // If there are no zeros, calculate the product of all elements divided by      the current element
        if (zeroCount == 0) {
            for (int i = 0; i < nums.size(); ++i) {
                output[i] = totalMult / nums[i];
            }
        } else if (zeroCount == 1) {
            // If there is only one zero, all elements in output should be zero except at the zero index
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == 0) {
                    output[i] = totalMult; // Assign totalMult at zero index
                    break;
                }
            }
        }
        
        return output;
    }
};
