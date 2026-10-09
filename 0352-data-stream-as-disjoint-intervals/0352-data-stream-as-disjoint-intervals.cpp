
class SummaryRanges {
private:
    set<int> nums;

public:
    SummaryRanges() {
    }

    void addNum(int value) {
        nums.insert(value);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;

        for (int num : nums) {
            if (ans.empty() || num > ans.back()[1] + 1) {
                ans.push_back({num, num});
            } else {
                ans.back()[1] = num;
            }
        }

        return ans;
    }
};