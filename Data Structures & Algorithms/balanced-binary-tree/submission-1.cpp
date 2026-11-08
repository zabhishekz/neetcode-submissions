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
    int dfs(TreeNode* root, bool &flag) {
        if(root == NULL){
            return 0;
        }
        int h1 = dfs(root->left,flag);
        int h2 = dfs(root->right,flag);
        if(h1 - h2 > 1 or h2 - h1 > 1){
            flag = false;
        }
        return 1 + max(h1,h2);
    }
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        int mH = dfs(root, flag);
        return flag;
    }
};
