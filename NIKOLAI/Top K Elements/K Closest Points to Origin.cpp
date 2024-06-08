#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    auto dist = [](vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    };
    priority_queue<pair<int, vector<int>>> pq;
    for (auto& point : points) {
        pq.push({dist(point), point});
        if (pq.size() > K) pq.pop();
    }
    vector<vector<int>> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}
