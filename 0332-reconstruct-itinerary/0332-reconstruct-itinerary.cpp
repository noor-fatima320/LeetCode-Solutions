class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> flights;
    vector<string> itinerary;

    void dfs(string airport) {
        while (!flights[airport].empty()) {
            string next = flights[airport].top();
            flights[airport].pop();

            dfs(next);
        }

        itinerary.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            flights[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");

        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};