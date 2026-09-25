class Solution {
public:
    string s;
    int pos = 0;

    set<string> parseExpression() {
        set<string> result;
        
        while (pos < s.size() && s[pos] != '}') {
            set<string> current = parseTerm();

            result.insert(current.begin(), current.end());

            if (pos < s.size() && s[pos] == ',') {
                pos++;
            }
        }

        return result;
    }

    set<string> parseTerm() {
        set<string> result = {""};

        while (pos < s.size() && s[pos] != '}' && s[pos] != ',') {
            set<string> part;

            if (s[pos] == '{') {
                pos++;
                part = parseExpression();
                pos++; // skip '}'
            } 
            else {
                part.insert(string(1, s[pos]));
                pos++;
            }

            set<string> next;

            for (const string& a : result) {
                for (const string& b : part) {
                    next.insert(a + b);
                }
            }

            result = next;
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        pos = 0;

        set<string> answer = parseExpression();

        return vector<string>(answer.begin(), answer.end());
    }
};