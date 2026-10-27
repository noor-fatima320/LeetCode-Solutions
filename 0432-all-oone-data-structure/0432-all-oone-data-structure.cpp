class AllOne {
private:
    struct Node {
        int count;
        unordered_set<string> keys;
        Node* prev;
        Node* next;

        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    unordered_map<string, Node*> keyNode;

    void insertAfter(Node* prevNode, Node* newNode) {
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (keyNode.find(key) == keyNode.end()) {
            Node* first = head->next;

            if (first == tail || first->count != 1) {
                Node* newNode = new Node(1);
                insertAfter(head, newNode);
                first = newNode;
            }

            first->keys.insert(key);
            keyNode[key] = first;
        } else {
            Node* current = keyNode[key];
            Node* nextNode = current->next;
            int newCount = current->count + 1;

            if (nextNode == tail || nextNode->count != newCount) {
                Node* newNode = new Node(newCount);
                insertAfter(current, newNode);
                nextNode = newNode;
            }

            nextNode->keys.insert(key);
            keyNode[key] = nextNode;

            current->keys.erase(key);

            if (current->keys.empty()) {
                removeNode(current);
            }
        }
    }

    void dec(string key) {
        Node* current = keyNode[key];

        if (current->count == 1) {
            current->keys.erase(key);
            keyNode.erase(key);

            if (current->keys.empty()) {
                removeNode(current);
            }
            return;
        }

        Node* prevNode = current->prev;
        int newCount = current->count - 1;

        if (prevNode == head || prevNode->count != newCount) {
            Node* newNode = new Node(newCount);
            insertAfter(prevNode, newNode);
            prevNode = newNode;
        }

        prevNode->keys.insert(key);
        keyNode[key] = prevNode;

        current->keys.erase(key);

        if (current->keys.empty()) {
            removeNode(current);
        }
    }

    string getMaxKey() {
        if (tail->prev == head) {
            return "";
        }

        return *(tail->prev->keys.begin());
    }

    string getMinKey() {
        if (head->next == tail) {
            return "";
        }

        return *(head->next->keys.begin());
    }
};