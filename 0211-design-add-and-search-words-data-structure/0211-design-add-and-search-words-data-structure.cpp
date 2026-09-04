class WordDictionary {
public:

    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;

            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* current = root;

        for (char c : word) {
            int index = c - 'a';

            if (current->child[index] == nullptr) {
                current->child[index] = new Node();
            }

            current = current->child[index];
        }

        current->isEnd = true;
    }

    bool searchWord(Node* current, string& word, int index) {

        if (index == word.size()) {
            return current->isEnd;
        }

        char c = word[index];

        // Normal letter
        if (c != '.') {
            int pos = c - 'a';

            if (current->child[pos] == nullptr) {
                return false;
            }

            return searchWord(current->child[pos], word, index + 1);
        }

        // '.' means any letter
        for (int i = 0; i < 26; i++) {

            if (current->child[i] != nullptr) {

                if (searchWord(current->child[i], word, index + 1)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool search(string word) {
        return searchWord(root, word, 0);
    }
};