class Solution {
public:
    int FindFirst(vector<int>& nums, int target) {
        int l=0, r= nums.size()-1;  
        while(l<=r){
            int mid = l - (l-r)/2;
            if(nums[mid] > target) r=mid-1;
            else if(nums[mid] < target) l = mid+1;
            else {
                if(mid==0 || nums[mid-1] != nums[mid]) {
                    return mid;
                }
                else r = mid-1;
            }
        }   
        return -1;
    }
    int FindLast(vector<int>& nums, int target) {
        int l=0, r= nums.size()-1, n = nums.size();  
        while(l<=r){
            int mid = l - (l-r)/2;
            if(nums[mid] > target) r=mid-1;
            else if(nums[mid] < target) l = mid+1;
            else {
                if(mid==n-1 || nums[mid] != nums[mid+1]) {
                    return mid;
                }
                else l =mid+1;
            }
        }   
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {FindFirst(nums, target), FindLast(nums, target)};
    }
};