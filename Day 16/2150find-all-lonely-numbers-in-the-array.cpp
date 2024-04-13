class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto &it : nums) mp[it]++;
        for(pair<int,int> n : mp)
        {
            int x = n.first;
            int y = n.second;
            if(y == 1 && mp.count(x+1) == 0 && mp.count(x-1) == 0)
                    ans.push_back(x);
        }
        return ans;
    }
};