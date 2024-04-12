class Solution {
public:
    string sortString(string s) {
        unordered_map<char,int>mp;
        string res = "";
        sort(s.begin(),s.end());
        for(auto nums : s)
            mp[nums]++;
        bool found = true;
        while(found)
        {
                found = false;

            for(char i = 'a' ; i <= 'z' ; i++)
            {
                if(mp[i])
                {
                    res.push_back(i);
                    mp[i]--;
                    found = true;
                }
            }
            for(char i = 'z' ; i >= 'a' ; i--)
            {
                
                if(mp[i])
                {
                    res.push_back(i);
                    mp[i]--;
                    found = true;
                }
            }
        }
    return res;
    }
};