class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        // Graph banana
        for (auto p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            graph[prerequisite].push_back(course);
            indegree[course]++;
        }

        // Jinke prerequisites nahi hain
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> answer;

        // Topological Sort
        while (!q.empty()) {
            int current = q.front();
            q.pop();

            answer.push_back(current);

            for (int next : graph[current]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // Agar saare courses complete nahi hue
        if (answer.size() != numCourses) {
            return {};
        }

        return answer;
    }
};