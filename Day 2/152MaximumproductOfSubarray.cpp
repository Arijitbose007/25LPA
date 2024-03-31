class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int Maxprod = nums[0];
        int Minprod = nums[0];
        int result = nums[0];
        for(int i = 1; i < nums.size() ; i++){
            if(nums[i] < 0)
                swap(Maxprod , Minprod); 
            Maxprod = max(nums[i] , Maxprod * nums[i]); 
            Minprod = min(nums[i] , Minprod * nums[i]); 
            
            result = max(result , Maxprod); 
        }
        return result;
    }
};
