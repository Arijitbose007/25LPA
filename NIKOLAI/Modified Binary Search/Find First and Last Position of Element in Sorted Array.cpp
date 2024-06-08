vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result(2, -1);
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            int l = mid, r = mid;
            while (l >= 0 && nums[l] == target) l--;
            while (r < nums.size() && nums[r] == target) r++;
            result[0] = l + 1;
            result[1] = r - 1;
            return result;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}
