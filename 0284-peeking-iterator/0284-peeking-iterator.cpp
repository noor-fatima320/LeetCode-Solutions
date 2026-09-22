class PeekingIterator : public Iterator {
private:
    int nextElement;
    bool hasPeeked;

public:
    PeekingIterator(const vector<int>& nums)
        : Iterator(nums) {
        hasPeeked = false;
    }

    int peek() {
        if (!hasPeeked) {
            nextElement = Iterator::next();
            hasPeeked = true;
        }

        return nextElement;
    }

    int next() {
        if (hasPeeked) {
            hasPeeked = false;
            return nextElement;
        }

        return Iterator::next();
    }

    bool hasNext() const {
        return hasPeeked || Iterator::hasNext();
    }
};