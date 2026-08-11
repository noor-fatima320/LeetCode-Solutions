class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= heights.size(); i++) {

            int currentHeight =
                (i == heights.size()) ? 0 : heights[i];

            while (!st.empty() &&
                   currentHeight < heights[st.top()]) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty()) {
                    width = i;
                }
                else {
                    width = i - st.top() - 1;
                }

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);

        int maxArea = 0;

        for (int i = 0; i < rows; i++) {

            // Build histogram
            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == '1') {
                    heights[j]++;
                }
                else {
                    heights[j] = 0;
                }
            }

            // Solve histogram
            maxArea = max(maxArea,
                          largestRectangleArea(heights));
        }

        return maxArea;
    }
};