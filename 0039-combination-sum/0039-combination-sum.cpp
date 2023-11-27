class Solution {
public:
    void backtracking(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& level, int idx, int target) {
        if(target ==0) ans.push_back(level);
        else {
            for(int i=idx; i<candidates.size(); i++) {
                if(candidates[i] > target) return;
                level.push_back(candidates[i]);
                backtracking(candidates, ans, level, i, target - candidates[i]);
                level.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> level;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, ans, level, 0, target);
        return ans;
    }
};