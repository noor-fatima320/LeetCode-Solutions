class Solution {
public:
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
if (n == 1) {
return {0};
}

    vector<vector<int>> graph(n);
    vector<int> degree(n, 0);

    for (auto edge : edges) {
        int a = edge[0];
        int b = edge[1];

        graph[a].push_back(b);
        graph[b].push_back(a);

        degree[a]++;
        degree[b]++;
    }

    queue<int> leaves;

    for (int i = 0; i < n; i++) {
        if (degree[i] == 1) {
            leaves.push(i);
        }
    }

    int remaining = n;

    while (remaining > 2) {
        int size = leaves.size();
        remaining -= size;

        for (int i = 0; i < size; i++) {
            int leaf = leaves.front();
            leaves.pop();

            for (int neighbor : graph[leaf]) {
                degree[neighbor]--;

                if (degree[neighbor] == 1) {
                    leaves.push(neighbor);
                }
            }
        }
    }

    vector<int> answer;

    while (!leaves.empty()) {
        answer.push_back(leaves.front());
        leaves.pop();
    }

    return answer;
}

};