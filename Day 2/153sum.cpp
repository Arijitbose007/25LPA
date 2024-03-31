class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        
        for(int i = 0 ; i < nums.size() - 2 ; i++){
            int j = i + 1;
            int k = nums.size() - 1;
            if(i>0 && nums[i] == nums[i-1]) continue;
            while(j<k)
                {    
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum > 0) k--;
                    else if(sum < 0) j++;
                    else{
                        temp = {nums[i] , nums[j] , nums[k]};
                        ans.push_back(temp);
                        j++;
                        k--;
                        while(j<k && nums[j-1] == nums[j]) j++;
                        while(j<k && nums[k+1] == nums[k]) k--;
                    }
                }
        }
    return ans;
    }
};