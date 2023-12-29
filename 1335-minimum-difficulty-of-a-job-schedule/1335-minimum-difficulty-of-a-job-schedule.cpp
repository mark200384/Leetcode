class Solution {
public:
    int minDifficulty(vector<int>& jobs, int d) {
        int n  =jobs.size();
        if(d > n) return -1;
        //dp[i][k]: min diff. to schedule the first i jobs(1-based) in k days
        vector<vector<int>> dp(n+1, vector<int>(d+1, INT_MAX/2));
        
        dp[0][0] = 0;
        for(int i=1; i<=n; i++) {
            for(int k=1; k<=d; k++) {
                int max_diff = 0;
                for(int j=i-1; j>=k-1; --j) {
                    max_diff = max(max_diff, jobs[j]);
                    dp[i][k] = min(dp[i][k], dp[j][k-1] + max_diff);
                }
            }
        }
        return dp[n][d];
    }
};