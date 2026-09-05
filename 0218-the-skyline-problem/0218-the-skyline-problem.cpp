class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, pair<int, int>>> events;

        // Building ke start aur end events
        for (auto& b : buildings) {
            int left = b[0];
            int right = b[1];
            int height = b[2];

            // Start event: negative height
            events.push_back({left, {-height, right}});

            // End event
            events.push_back({right, {0, 0}});
        }

        sort(events.begin(), events.end());

        // {height, right}
        priority_queue<pair<int, int>> pq;

        // Ground level
        pq.push({0, INT_MAX});

        vector<vector<int>> result;
        int previousHeight = 0;

        for (auto& event : events) {
            int x = event.first;
            int height = event.second.first;
            int right = event.second.second;

            if (height < 0) {
                // New building start
                pq.push({-height, right});
            }

            // Expired buildings remove karo
            while (!pq.empty() && pq.top().second <= x) {
                pq.pop();
            }

            int currentHeight = pq.top().first;

            // Height change hui to key point add karo
            if (currentHeight != previousHeight) {
                result.push_back({x, currentHeight});
                previousHeight = currentHeight;
            }
        }

        return result;
    }
};