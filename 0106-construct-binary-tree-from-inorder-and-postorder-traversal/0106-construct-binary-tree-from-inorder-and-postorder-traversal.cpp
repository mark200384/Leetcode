/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || postorder.empty()) {
            return nullptr;
        }
        int mid=0, val=postorder.back();
        TreeNode* root=new TreeNode(val);
        for(int i=0; i<inorder.size(); i++) {
            if(inorder[i] == val) {
                mid = i;
            }
        }
        vector<int> in_l(inorder.begin(), inorder.begin()+mid);
        vector<int> in_r(inorder.begin()+mid+1, inorder.end());
        vector<int> l(postorder.begin(), postorder.begin()+mid);
        vector<int> r(postorder.begin()+mid,postorder.end()-1);
        
        root->left = buildTree(in_l, l);
        root->right = buildTree(in_r, r);
        
        return root;
    }
};