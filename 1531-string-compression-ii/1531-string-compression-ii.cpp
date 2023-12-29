class Solution {
public:
    //dp[i][last][l][k] : 第i個, 最後一個字母是甚麼(a-z):26, 長度l, 刪k個
    
     // dp[left][k] means the minimal coding size for substring 
    // s[left:] and removing at most k chars
    string s;
    int dp[127][127];
    int n;
    int get_len(int x) {
        if(x==1) return 0;
        else if(x<10) return 1;
        else if(x<100) return 2;
        else return 3;
    }
    int solve(int left, int k) {
        if(k<0) return INT_MAX/2;
        if(left>=n || n-left<=k) return 0; 
        int &res = dp[left][k];
        if(res != -1) return res;
        res = INT_MAX/2;
        int count[26]={0};
        // we try to make s[left:j] (both inculded) as one group,
        // and all chars in this group should be the same.
        // so we must keep the most chars in this range and remove others
        // the range length is (j - left + 1)
        // and the number of chars we need to remove is (j - left + 1 - most)
        for(int j = left, most = 0; j < n; j++) {
            most = max(most, ++count[s[j] - 'a']);  // most = max(count(s[left:j])
            res = min(res, 1 + get_len(most) + solve(j + 1, k - (j - left + 1 - most)));
        }
        return res;
    }

    int getLengthOfOptimalCompression(string str, int k) {
        memset(dp, -1, sizeof(dp));
        s = str;
        n = s.size();
        return solve(0, k);
    }
};