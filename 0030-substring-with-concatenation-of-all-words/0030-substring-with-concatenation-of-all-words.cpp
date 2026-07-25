class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        if(words.empty()) return ans;

        int wordLen = words[0].length();
        int totalWords = words.size();
        int totalLen = wordLen * totalWords;

        if(s.length() < totalLen)
            return ans;


        unordered_map<string,int> wordCount;

        for(string word : words) {
            wordCount[word]++;
        }


        // Try every possible starting offset
        for(int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int right = offset;
            int count = 0;

            unordered_map<string,int> window;


            while(right + wordLen <= s.length()) {

                string word = s.substr(right, wordLen);

                right += wordLen;


                if(wordCount.find(word) != wordCount.end()) {

                    window[word]++;
                    count++;


                    // Remove extra occurrence
                    while(window[word] > wordCount[word]) {

                        string leftWord = s.substr(left, wordLen);

                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }


                    // All words matched
                    if(count == totalWords) {

                        ans.push_back(left);

                        // Move left for next possible answer
                        string leftWord = s.substr(left, wordLen);

                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                }
                else {

                    // Reset window
                    window.clear();
                    count = 0;
                    left = right;
                }
            }
        }


        return ans;
    }
};