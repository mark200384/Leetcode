class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> set(to_delete.begin(), to_delete.end());
        helper(root, set, res, true);
        return res;
    }
    TreeNode* helper(TreeNode* node, unordered_set<int>& set, vector<TreeNode*> &res, bool is_root) {
        if(!node) return nullptr;
        bool deleted = set.count(node->val);
        //是不是要刪除的node
        if(!deleted && is_root) res.push_back(node);
        node->left = helper(node->left, set, res, deleted);//如果是被刪除的點, 則當前左子樹是新的root
        node->right = helper(node->right, set, res, deleted);
        return deleted? nullptr:node;
    }
};