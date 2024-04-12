class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());
    
        reverse(nums.begin(),nums.end());
    }
};

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//        k = k % nums.size();

//        // Reverse the first part (left part)
//        reverse(nums.begin(), nums.begin() + k);

//        // Reverse the second part (right part)
//        reverse(nums.begin() + k, nums.end());

//        // Reverse the entire array
//        reverse(nums.begin(), nums.end());
//     }
// };