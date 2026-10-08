class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        
        int leftRemove = 0;
        int rightRemove = 0;
        
        for (char c : s) {
            if (c == '(') {
                leftRemove++;
            }
            else if (c == ')') {
                if (leftRemove > 0)
                    leftRemove--;
                else
                    rightRemove++;
            }
        }
        
        function<void(int, int, int, string)> dfs =
            [&](int pos, int left, int right, string current) {
                
                if (pos == s.size()) {
                    if (left == 0 && right == 0) {
                        ans.push_back(current);
                    }
                    return;
                }
                
                char c = s[pos];
                
                if (c == '(' && left > 0) {
                    dfs(pos + 1, left - 1, right, current);
                }
                
                if (c == ')' && right > 0) {
                    dfs(pos + 1, left, right - 1, current);
                }
                
                current += c;
                
                if (c != '(' && c != ')') {
                    dfs(pos + 1, left, right, current);
                }
                else {
                    int balance = 0;
                    
                    for (char ch : current) {
                        if (ch == '(')
                            balance++;
                        else if (ch == ')')
                            balance--;
                        
                        if (balance < 0)
                            return;
                    }
                    
                    dfs(pos + 1, left, right, current);
                }
            };
        
        dfs(0, leftRemove, rightRemove, "");
        
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};