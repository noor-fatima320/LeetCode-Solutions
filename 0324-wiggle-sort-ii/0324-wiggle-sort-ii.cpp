class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        int n = nums.size();
        
        // Make a sorted copy
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        // Middle point
        int mid = (n + 1) / 2;
        
        // Pointers for the two halves
        int small = mid - 1;
        int large = n - 1;
        
        // Fill positions: 0, 1, 2, 3...
        for (int i = 0; i < n; i++) {
            
            if (i % 2 == 0) {
                // Even positions get smaller values
                nums[i] = sorted[small--];
            }
            else {
                // Odd positions get larger values
                nums[i] = sorted[large--];
            }
        }
    }
};