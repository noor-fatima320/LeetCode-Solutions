class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        // ASCII characters ke liye mapping
        vector<int> mapST(256, -1);
        vector<int> mapTS(256, -1);

        for (int i = 0; i < s.length(); i++) {
            
            char a = s[i];
            char b = t[i];

            // s -> t mapping already exist karti hai
            if (mapST[a] != -1 && mapST[a] != b) {
                return false;
            }

            // t -> s mapping already exist karti hai
            if (mapTS[b] != -1 && mapTS[b] != a) {
                return false;
            }

            // Dono directions mein mapping save karo
            mapST[a] = b;
            mapTS[b] = a;
        }

        return true;
    }
};