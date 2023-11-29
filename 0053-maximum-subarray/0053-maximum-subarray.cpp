class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> res(nums.size());
        res[0] = nums[0];
        for(int i=1; i<nums.size(); i++) {
            res[i] = max(res[i-1] + nums[i], nums[i]);
        }
        
        return *max_element(res.begin(), res.end());
    }
};