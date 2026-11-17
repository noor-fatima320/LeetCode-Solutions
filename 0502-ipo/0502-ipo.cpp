
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> projects;

        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxHeap;

        int j = 0;

        for (int i = 0; i < k; i++) {

            // Add all projects we can currently afford
            while (j < n && projects[j].first <= w) {
                maxHeap.push(projects[j].second);
                j++;
            }

            // No affordable project left
            if (maxHeap.empty()) {
                break;
            }

            // Select project with maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};
