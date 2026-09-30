class Solution {
public:
vector<string> result;
unordered_set<string> visited;


bool isValid(string s) {
    int balance = 0;

    for (char c : s) {
        if (c == '(') {
            balance++;
        } else if (c == ')') {
            balance--;

            if (balance < 0) {
                return false;
            }
        }
    }

    return balance == 0;
}

void dfs(string s, int index, int removeCount, int minRemove) {
    if (removeCount > minRemove) {
        return;
    }

    if (visited.count(s)) {
        return;
    }

    visited.insert(s);

    if (isValid(s)) {
        if (removeCount == minRemove) {
            result.push_back(s);
        }
        return;
    }

    for (int i = index; i < s.length(); i++) {
        if (s[i] != '(' && s[i] != ')') {
            continue;
        }

        if (i > index && s[i] == s[i - 1]) {
            continue;
        }

        string next = s.substr(0, i) + s.substr(i + 1);

        dfs(next, i, removeCount + 1, minRemove);
    }
}

int getMinRemove(string s) {
    int balance = 0;
    int remove = 0;

    for (char c : s) {
        if (c == '(') {
            balance++;
        } else if (c == ')') {
            if (balance > 0) {
                balance--;
            } else {
                remove++;
            }
        }
    }

    return remove + balance;
}


public:
vector<string> removeInvalidParentheses(string s) {
result.clear();
visited.clear();


    int minRemove = getMinRemove(s);

    dfs(s, 0, 0, minRemove);

    return result;
}


};
