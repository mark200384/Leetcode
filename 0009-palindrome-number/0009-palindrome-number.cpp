class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x!=0 && x%10 ==0)) 
            return false;
        
        int reversed=0;
        while(x > reversed) {//只翻轉一半
            reversed = reversed*10 + x%10;
            x /= 10;
        }
        //判斷偶數 || 判斷奇數(跳過一個數字)
        return (x==reversed) || (x == reversed/10);
    }
};