
class Solution {
    double r, xc, yc;

public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        xc = x_center;
        yc = y_center;

        srand(time(0));
    }

    vector<double> randPoint() {
        while (true) {
            double x = ((double)rand() / RAND_MAX) * 2 * r - r;
            double y = ((double)rand() / RAND_MAX) * 2 * r - r;

            if (x * x + y * y <= r * r) {
                return {xc + x, yc + y};
            }
        }
    }
};
