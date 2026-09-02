class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Graph banayenge
        vector<vector<int>> graph(numCourses);

        // Har course ki incoming dependencies count
        vector<int> indegree(numCourses, 0);

        // Graph create karna
        for (auto& p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            graph[prerequisite].push_back(course);
            indegree[course]++;
        }

        // Jin courses ki koi prerequisite nahi hai
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Courses process karna
        int completed = 0;

        while (!q.empty()) {

            int course = q.front();
            q.pop();

            completed++;

            // Is course ke baad jo courses unlock honge
            for (int next : graph[course]) {

                indegree[next]--;

                // Ab is course ki saari prerequisites complete hain
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // Agar saare courses complete ho gaye
        return completed == numCourses;
    }
};