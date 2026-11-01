class LFUCache {
private:
    int capacity;
    int minFreq;

    unordered_map<int, pair<int, int>> keyInfo;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> position;

    void updateFreq(int key) {
        int freq = keyInfo[key].second;

        freqList[freq].erase(position[key]);

        if (freqList[freq].empty()) {
            freqList.erase(freqList.find(freq));

            if (minFreq == freq) {
                minFreq++;
            }
        }

        keyInfo[key].second++;

        int newFreq = keyInfo[key].second;

        freqList[newFreq].push_front(key);
        position[key] = freqList[newFreq].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyInfo.find(key) == keyInfo.end()) {
            return -1;
        }

        int value = keyInfo[key].first;

        updateFreq(key);

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        if (keyInfo.find(key) != keyInfo.end()) {
            keyInfo[key].first = value;
            updateFreq(key);
            return;
        }

        if (keyInfo.size() == capacity) {
            int lfuKey = freqList[minFreq].back();

            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty()) {
                freqList.erase(minFreq);
            }

            keyInfo.erase(lfuKey);
            position.erase(lfuKey);
        }

        keyInfo[key] = {value, 1};

        freqList[1].push_front(key);
        position[key] = freqList[1].begin();

        minFreq = 1;
    }
};