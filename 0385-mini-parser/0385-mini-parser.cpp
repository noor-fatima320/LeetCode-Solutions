class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }

        stack<NestedInteger> st;
        int num = 0;
        int sign = 1;
        bool readingNum = false;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == '[') {
                st.push(NestedInteger());
            }
            else if (c == '-' ) {
                sign = -1;
            }
            else if (isdigit(c)) {
                num = num * 10 + (c - '0');
                readingNum = true;
            }
            else if (c == ',' || c == ']') {
                if (readingNum) {
                    st.top().add(NestedInteger(sign * num));
                    num = 0;
                    sign = 1;
                    readingNum = false;
                }

                if (c == ']') {
                    NestedInteger current = st.top();
                    st.pop();

                    if (st.empty()) {
                        return current;
                    }

                    st.top().add(current);
                }
            }
        }

        return NestedInteger();
    }
};