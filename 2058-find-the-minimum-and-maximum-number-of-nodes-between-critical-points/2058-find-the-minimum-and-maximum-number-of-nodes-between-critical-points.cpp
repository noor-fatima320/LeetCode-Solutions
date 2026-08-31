class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDist = INT_MAX;
        int maxDist = -1;

        int first = -1;   // First critical point
        int prev = -1;    // Previous critical point

        int pos = 1;

        ListNode* previous = head;
        ListNode* current = head->next;

        while (current != nullptr && current->next != nullptr) {

            ListNode* next = current->next;

            // Check if current node is a critical point
            bool isMax = (current->val > previous->val &&
                          current->val > next->val);

            bool isMin = (current->val < previous->val &&
                          current->val < next->val);

            if (isMax || isMin) {

                // This is the first critical point
                if (first == -1) {
                    first = pos;
                }

                // We already have a previous critical point
                if (prev != -1) {
                    minDist = min(minDist, pos - prev);
                    maxDist = max(maxDist, pos - first);
                }

                prev = pos;
            }

            previous = current;
            current = next;
            pos++;
        }

        // Fewer than two critical points
        if (minDist == INT_MAX) {
            return {-1, -1};
        }

        return {minDist, maxDist};
    }
};