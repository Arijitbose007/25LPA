class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto temp : nums)
            mp[temp]++;
        vector<int>res;
        for(const auto& pair : mp)
        {
            if(pair.second == 2)
                res.push_back(pair.first);
        }
    return res;
    }
};