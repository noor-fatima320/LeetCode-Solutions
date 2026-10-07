class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1;

        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] == ',')
                continue;

            if (slots == 0)
                return false;

            if (preorder[i] == '#') {
                slots--;
            } 
            else {
                slots++;
            }

            while (i < preorder.size() && preorder[i] != ',')
                i++;
        }

        return slots == 0;
    }
};