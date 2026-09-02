class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasOdd = false;
        bool hasEven = false;

        for (int x : nums1) {
            if (x % 2 == 0)
                hasEven = true;
            else
                hasOdd = true;
        }

        // Agar saare already same parity ke hain
        if (!hasOdd || !hasEven)
            return true;

        // Agar odd aur even dono hain,
        // kisi bhi even number ko odd banane ke liye
        // odd number se subtract kar sakte hain.
        return true;
    }
};