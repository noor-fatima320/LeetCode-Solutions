
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;

            int slow = i, fast = i;
            bool forward = nums[i] > 0;

            while (true) {
                // Move slow pointer
                int next = ((slow + nums[slow]) % n + n) % n;

                if (nums[next] == 0 || (nums[next] > 0) != forward)
                    break;

                slow = next;

                // Move fast pointer once
                int nextFast = ((fast + nums[fast]) % n + n) % n;

                if (nums[nextFast] == 0 || (nums[nextFast] > 0) != forward)
                    break;

                fast = nextFast;

                // Move fast pointer second time
                nextFast = ((fast + nums[fast]) % n + n) % n;

                if (nums[nextFast] == 0 || (nums[nextFast] > 0) != forward)
                    break;

                fast = nextFast;

                if (slow == fast) {
                    if (slow != ((slow + nums[slow]) % n + n) % n)
                        return true;

                    break;
                }
            }

            // Mark visited elements
            int curr = i;

            while (nums[curr] != 0 && (nums[curr] > 0) == forward) {
                int next = ((curr + nums[curr]) % n + n) % n;

                nums[curr] = 0;
                curr = next;
            }
        }

        return false;
    }
};
