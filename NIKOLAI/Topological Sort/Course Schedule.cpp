#include <vector>
#include <queue>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adjList(numCourses);
    vector<int> inDegree(numCourses, 0);
    queue<int> q;
    
    for (const auto& prereq : prerequisites) {
        adjList[prereq[1]].push_back(prereq[0]);
        inDegree[prereq[0]]++;
    }
    
    for (int i = 0; i < numCourses; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    int count = 0;
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        count++;
        
        for (int nextCourse : adjList[course]) {
            if (--inDegree[nextCourse] == 0) {
                q.push(nextCourse);
            }
        }
    }
    
    return count == numCourses;
}
