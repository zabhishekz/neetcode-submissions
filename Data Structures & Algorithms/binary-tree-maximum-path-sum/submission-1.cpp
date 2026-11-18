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
    int res;
public:
    int maxPathSum(TreeNode* root) {
        res = root->val;
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        res = max({res, root->val, root->val + left, root->val + right, root->val + left + right});
        return max({root->val, root->val + left, root->val + right});
    }
};
