class Solution {
    vector<vector<int>> rects;
    vector<long long> prefix;
    long long total;
    mt19937 rng;

public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        total = 0;
        rng = mt19937(random_device{}());

        for (auto& r : rects) {
            long long points = (long long)(r[2] - r[0] + 1) *
                               (r[3] - r[1] + 1);

            total += points;
            prefix.push_back(total);
        }
    }

    vector<int> pick() {
        uniform_int_distribution<long long> dist(1, total);
        long long target = dist(rng);

        int idx = lower_bound(prefix.begin(), prefix.end(), target)
                  - prefix.begin();

        long long prev = (idx == 0) ? 0 : prefix[idx - 1];
        long long offset = target - prev - 1;

        int width = rects[idx][2] - rects[idx][0] + 1;

        int x = rects[idx][0] + offset % width;
        int y = rects[idx][1] + offset / width;

        return {x, y};
    }
};