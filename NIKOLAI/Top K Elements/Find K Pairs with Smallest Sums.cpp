#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            if (pq.size() < k) {
                pq.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            } else if (nums1[i] + nums2[j] < pq.top().first) {
                pq.pop();
                pq.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            } else {
                break;
            }
        }
    }
    vector<pair<int, int>> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}
