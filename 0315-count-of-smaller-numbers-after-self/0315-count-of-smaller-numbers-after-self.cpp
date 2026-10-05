class Solution {
public:
void mergeSort(vector<pair<int, int>>& nums, vector<int>& counts, int left, int right) {
if (left >= right) {
return;
}

    int mid = left + (right - left) / 2;

    mergeSort(nums, counts, left, mid);
    mergeSort(nums, counts, mid + 1, right);

    vector<pair<int, int>> temp;

    int i = left;
    int j = mid + 1;
    int smaller = 0;

    while (i <= mid && j <= right) {
        if (nums[j].first < nums[i].first) {
            temp.push_back(nums[j]);
            smaller++;
            j++;
        } else {
            counts[nums[i].second] += smaller;
            temp.push_back(nums[i]);
            i++;
        }
    }

    while (i <= mid) {
        counts[nums[i].second] += smaller;
        temp.push_back(nums[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(nums[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        nums[left + k] = temp[k];
    }
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();

    vector<int> counts(n, 0);
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++) {
        arr.push_back({nums[i], i});
    }

    mergeSort(arr, counts, 0, n - 1);

    return counts;
}

};