class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reserved;

        for (auto &seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }

        int ans = 2 * n;

        for (auto &[row, seats] : reserved) {

            bool left = true;
            bool middle = true;
            bool right = true;

            // Seats 2,3,4,5
            for (int s = 2; s <= 5; s++) {
                if (seats.count(s)) {
                    left = false;
                    break;
                }
            }

            // Seats 4,5,6,7
            for (int s = 4; s <= 7; s++) {
                if (seats.count(s)) {
                    middle = false;
                    break;
                }
            }

            // Seats 6,7,8,9
            for (int s = 6; s <= 9; s++) {
                if (seats.count(s)) {
                    right = false;
                    break;
                }
            }

            if (left && right) {
                // 2 groups possible
            }
            else if (left || middle || right) {
                // 1 group possible
                ans--;
            }
            else {
                // 0 groups possible
                ans -= 2;
            }
        }

        return ans;
    }
};