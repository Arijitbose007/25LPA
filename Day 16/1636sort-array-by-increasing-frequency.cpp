#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) {
        std::unordered_map<int, int> mp;
        for (int temp : nums)
            mp[temp]++;

        sort(nums.begin(), nums.end(),[&](int a , int b)
        {
            if(mp[a] == mp[b]) return a > b;
            return mp[a] <>>  mp[b];
        });

        return nums;
    }
};
// Note a will be or the 1st one mentioned in the lamda function will hve the dominant character, the comparision will be based on that.
// The if statement compares the frequencies of elements a and b:
// If the frequencies are equal (mp[a] == mp[b]), the lambda function returns the result of a > b. This means that if a is greater than b (in terms of their values), it will be placed before b in the sorted sequence.
// If the frequencies are not equal, the lambda function returns the result of mp[a] < mp[b]. This means that if the frequency of a is less than the frequency of b, a will be placed before b in the sorted sequence.