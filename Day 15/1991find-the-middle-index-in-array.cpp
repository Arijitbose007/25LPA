class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        int index = -1, ans;
        int leftsum ,rightsum = 0;
        for(int temp : nums)
        {
            rightsum += temp;
        }
        int sum = rightsum;
        for(int i = 0 ; i < n ; i++)
        {
            rightsum -= nums[i];
            leftsum = sum - (rightsum + nums[i]);
             if(leftsum == rightsum)
            {
                ans = i;
                break;
            }
        }
        if(leftsum != rightsum) ans = -1;
        return ans;
    }
};