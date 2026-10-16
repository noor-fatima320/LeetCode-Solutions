
class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> pos;

public:
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool notPresent = pos[val].empty();

        pos[val].insert(nums.size());
        nums.push_back(val);

        return notPresent;
    }
    
    bool remove(int val) {
        if (pos.find(val) == pos.end() || pos[val].empty()) {
            return false;
        }

        int index = *pos[val].begin();
        int lastIndex = nums.size() - 1;
        int lastVal = nums[lastIndex];

        pos[val].erase(index);

        if (index != lastIndex) {
            nums[index] = lastVal;

            pos[lastVal].erase(lastIndex);
            pos[lastVal].insert(index);
        }

        nums.pop_back();

        if (pos[val].empty()) {
            pos.erase(val);
        }

        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
