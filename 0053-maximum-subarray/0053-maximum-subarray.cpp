class Solution {
public:
    // brute force:O(n^2)
    // devide & conquer: O(nlogn)
    int maxSubArray(vector<int>& nums) {
        return DevideConquer(nums, 0, nums.size()-1);
    }
    int DevideConquer(vector<int>& nums, int left, int right) {
        if(left > right) return INT_MIN;
        int mid = left - (left - right)/2, leftSum=0, rightSum=0;
        for(int i = mid-1, curSum = 0; i >= left; i--){
            curSum += nums[i],
            leftSum = max(leftSum, curSum);
        }
        for(int i=mid+1, curSum=0; i<=right; i++) {
            curSum += nums[i];
            rightSum = max(rightSum, curSum);
        }
        return max({ DevideConquer(nums, left, mid-1), DevideConquer(nums, mid+1, right), leftSum + nums[mid] + rightSum });
    }
    
};