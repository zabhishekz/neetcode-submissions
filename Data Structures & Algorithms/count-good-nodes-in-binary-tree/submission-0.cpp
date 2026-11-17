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
    int res = 0;
public:
    void dfs(TreeNode* root, int depth, int currMax){
        if(root == NULL) return;

        if(root->val >= currMax){
            res++;
        }
        dfs(root->left, depth+1, max(currMax,root->val));
        dfs(root->right, depth+1, max(currMax,root->val));
    }
    int goodNodes(TreeNode* root) {
        dfs(root, 0, INT_MIN);
        return res;
    }
};
