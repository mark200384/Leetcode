class Solution {
public:
//这个方法实际上不是严格的O(n)复杂度，它的效率比直接在范围内进行逐个位与操作的方法要高。
/*right & (right - 1)操作有效地去除了right最低位的1。这意味着每次操作都会减少right中1的数量，直到right小于或等于left。在二进制中，每个数字1的位置可以非常快地减少到与left相同的位级，尤其是在大范围内。*/ 
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        // 找到left和right的最左边共同位。
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        // 将共同位左移回它们原来的位置。
        return left << shift;
    }
};
/*
5  0101
6  0110
7  0111
对于任何位位置，如果至少有一个'0'和一个'1'，结果将是'0'。
优化的关键在于，两个数字的位与操作只保留两个数字最左边共同的位不变，如果数字不同，所有后续位都变成零。
*/