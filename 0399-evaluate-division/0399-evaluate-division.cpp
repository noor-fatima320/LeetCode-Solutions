
class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string start, string target,
               unordered_set<string>& visited) {
        if (graph.find(start) == graph.end() ||
            graph.find(target) == graph.end()) {
            return -1.0;
        }

        if (start == target) {
            return 1.0;
        }

        visited.insert(start);

        for (auto& edge : graph[start]) {
            string next = edge.first;
            double weight = edge.second;

            if (visited.count(next)) {
                continue;
            }

            double result = dfs(next, target, visited);

            if (result != -1.0) {
                return weight * result;
            }
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries) {

        graph.clear();

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];

            graph[a].push_back({b, value});
            graph[b].push_back({a, 1.0 / value});
        }

        vector<double> answers;

        for (auto& query : queries) {
            unordered_set<string> visited;

            answers.push_back(
                dfs(query[0], query[1], visited)
            );
        }

        return answers;
    }
};
