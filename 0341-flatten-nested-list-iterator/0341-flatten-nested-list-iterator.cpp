
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     bool isInteger() const;
 *     int getInteger() const;
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<NestedInteger> st;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = (int)nestedList.size() - 1; i >= 0; i--) {
            st.push(nestedList[i]);
        }
    }

    int next() {
        int result = st.top().getInteger();
        st.pop();
        return result;
    }

    bool hasNext() {
        while (!st.empty()) {
            NestedInteger curr = st.top();

            if (curr.isInteger()) {
                return true;
            }

            st.pop();
            const vector<NestedInteger>& lst = curr.getList();

            for (int i = (int)lst.size() - 1; i >= 0; i--) {
                st.push(lst[i]);
            }
        }

        return false;
    }
};