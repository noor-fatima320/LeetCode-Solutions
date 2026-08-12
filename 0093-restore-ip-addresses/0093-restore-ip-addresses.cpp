class Solution {
public:
    vector<string> result;

    void backtrack(string& s, int index, int parts, string current) {
        // 4 parts complete
        if (parts == 4) {
            if (index == s.size()) {
                current.pop_back(); // last dot remove
                result.push_back(current);
            }
            return;
        }

        // Ek part mein maximum 3 digits
        for (int len = 1; len <= 3; len++) {
            if (index + len > s.size()) {
                break;
            }

            string part = s.substr(index, len);

            // Leading zero allowed nahi
            if (part.size() > 1 && part[0] == '0') {
                continue;
            }

            // Value 255 se zyada nahi honi chahiye
            if (stoi(part) > 255) {
                continue;
            }

            backtrack(
                s,
                index + len,
                parts + 1,
                current + part + "."
            );
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return result;
    }
};