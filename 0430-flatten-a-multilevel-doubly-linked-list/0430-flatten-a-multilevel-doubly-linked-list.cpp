
class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->child != nullptr) {
                Node* nextNode = curr->next;

                Node* childList = flatten(curr->child);

                curr->next = childList;
                childList->prev = curr;
                curr->child = nullptr;

                Node* tail = childList;

                while (tail->next != nullptr) {
                    tail = tail->next;
                }

                tail->next = nextNode;

                if (nextNode != nullptr) {
                    nextNode->prev = tail;
                }
            }

            curr = curr->next;
        }

        return head;
    }
};
