class Solution {
public:
    vector<long long> ans;
    vector<long long> sumOfThree(long long num) {
        if(num%3!=0)    return ans;
        else{
            ans.push_back(num/3-1);
            ans.push_back(num/3);
            ans.push_back(num/3+1);
        }
        return ans;
    }
};