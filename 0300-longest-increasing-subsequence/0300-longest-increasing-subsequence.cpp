class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1, n = size(nums);
        vector<int> dp(n, 1);//dp[i] 表示以索引 i 結尾的 LIS
        /*每個元素nums[i]，如果它前面有一個更小的元素nums[j]，則結果將是以i 結尾的當前LIS 長度的
        最大值：dp[i]，以及以j + 1 結尾的LIS：dp[j ] + 1. +1*/
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
				    dp[i] = max(dp[i], dp[j] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};