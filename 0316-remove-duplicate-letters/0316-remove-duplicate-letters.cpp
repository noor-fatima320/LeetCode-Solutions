class Solution {
public:
string removeDuplicateLetters(string s) {
vector<int> last(26, 0);
vector<bool> used(26, false);
string st;

    for (int i = 0; i < s.length(); i++) {
        last[s[i] - 'a'] = i;
    }

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (used[c - 'a']) {
            continue;
        }

        while (!st.empty() &&
               st.back() > c &&
               last[st.back() - 'a'] > i) {
            used[st.back() - 'a'] = false;
            st.pop_back();
        }

        st.push_back(c);
        used[c - 'a'] = true;
    }

    return st;
}

};