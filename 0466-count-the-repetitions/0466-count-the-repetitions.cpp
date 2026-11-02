class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {

        int count1 = 0;
        int count2 = 0;
        int index = 0;

        unordered_map<int, pair<int, int>> mp;

        while (count1 < n1) {

            for (char c : s1) {

                if (c == s2[index]) {
                    index++;

                    if (index == s2.size()) {
                        index = 0;
                        count2++;
                    }
                }
            }

            count1++;

            if (mp.find(index) != mp.end()) {

                int prevCount1 = mp[index].first;
                int prevCount2 = mp[index].second;

                int cycleCount1 = count1 - prevCount1;
                int cycleCount2 = count2 - prevCount2;

                int remaining = n1 - count1;

                int cycles = remaining / cycleCount1;

                count1 += cycles * cycleCount1;
                count2 += cycles * cycleCount2;

            } 
            else {
                mp[index] = {count1, count2};
            }
        }

        return count2 / n2;
    }
};