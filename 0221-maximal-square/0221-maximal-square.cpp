class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int res=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j]=='1') {
                    dp[i+1][j+1] = min({dp[i][j], dp[i+1][j], dp[i][j+1]}) + 1;
                    res = max(res, dp[i+1][j+1]);
                }
            }
        }
        return pow(res, 2);
    }
};