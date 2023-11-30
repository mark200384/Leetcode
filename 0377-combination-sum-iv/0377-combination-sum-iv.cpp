class Solution {
public:
    unordered_map<int, int> memo;

    int backtracking(vector<int>& nums, int target) {
        if (target == 0) {
            return 1;
        }

        if (memo.find(target) != memo.end()) {
            return memo[target];
        }

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target >= nums[i]) {
                count += backtracking(nums, target - nums[i]);
            }
        }

        memo[target] = count;
        return count;
    }

    int combinationSum4(vector<int>& nums, int target) {
        return backtracking(nums, target);
    }
};
