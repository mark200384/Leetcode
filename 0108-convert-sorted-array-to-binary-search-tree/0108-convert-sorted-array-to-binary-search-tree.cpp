class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        int middle = (left + right) / 2;
        TreeNode* newNode = new TreeNode(nums[middle]);
        
        newNode->left = sortedArrayToBST(nums, left, middle-1);
        newNode->right = sortedArrayToBST(nums, middle+1, right);

        return newNode;
    }
};