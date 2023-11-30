class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, ptr1 = a.length() - 1, ptr2 = b.length() - 1;
        string res;
        
        while (ptr1 >= 0 || ptr2 >= 0 || carry) {
            int bitA = (ptr1 >= 0) ? a[ptr1] - '0' : 0;
            int bitB = (ptr2 >= 0) ? b[ptr2] - '0' : 0;

            int sum = bitA + bitB + carry;
            res += (sum % 2) + '0'; // Append the character '0' or '1'
            carry = sum / 2;

            ptr1--, ptr2--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
