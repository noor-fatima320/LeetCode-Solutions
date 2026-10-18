
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long area = 0;

        int minX = INT_MAX;
        int minY = INT_MAX;
        int maxX = INT_MIN;
        int maxY = INT_MIN;

        unordered_set<string> corners;

        for (auto& r : rectangles) {
            int x1 = r[0], y1 = r[1];
            int x2 = r[2], y2 = r[3];

            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            area += 1LL * (x2 - x1) * (y2 - y1);

            vector<pair<int, int>> points = {
                {x1, y1}, {x1, y2},
                {x2, y1}, {x2, y2}
            };

            for (auto& p : points) {
                string key = to_string(p.first) + "," +
                             to_string(p.second);

                if (corners.count(key)) {
                    corners.erase(key);
                } else {
                    corners.insert(key);
                }
            }
        }

        long long totalArea =
            1LL * (maxX - minX) * (maxY - minY);

        if (area != totalArea) {
            return false;
        }

        if (corners.size() != 4) {
            return false;
        }

        vector<string> expected = {
            to_string(minX) + "," + to_string(minY),
            to_string(minX) + "," + to_string(maxY),
            to_string(maxX) + "," + to_string(minY),
            to_string(maxX) + "," + to_string(maxY)
        };

        for (string& point : expected) {
            if (!corners.count(point)) {
                return false;
            }
        }

        return true;
    }
};
