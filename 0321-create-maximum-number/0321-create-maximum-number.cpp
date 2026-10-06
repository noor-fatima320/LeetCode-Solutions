class Solution {
public:

    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> st;
        int remove = nums.size() - k;

        for (int x : nums) {
            while (!st.empty() && remove > 0 && st.back() < x) {
                st.pop_back();
                remove--;
            }

            st.push_back(x);
        }

        st.resize(k);
        return st;
    }

    bool greaterVector(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }

        if (j == b.size())
            return true;

        if (i == a.size())
            return false;

        return a[i] > b[j];
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> result;

        int i = 0;
        int j = 0;

        while (i < a.size() || j < b.size()) {
            if (greaterVector(a, i, b, j)) {
                result.push_back(a[i]);
                i++;
            }
            else {
                result.push_back(b[j]);
                j++;
            }
        }

        return result;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<int> answer;

        int m = nums1.size();
        int n = nums2.size();

        int start = max(0, k - n);
        int end = min(k, m);

        for (int x = start; x <= end; x++) {

            int y = k - x;

            vector<int> part1 = maxSubsequence(nums1, x);
            vector<int> part2 = maxSubsequence(nums2, y);

            vector<int> candidate = merge(part1, part2);

            if (answer.empty() || candidate > answer) {
                answer = candidate;
            }
        }

        return answer;
    }
};