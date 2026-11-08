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
    // We do the maxHeight calculation only recursively. 
    // The only difference is for each node, we also calculate teh diameter by summing the heights and maintain a global value for this as teh maximum diamter
    int maxHeight(TreeNode* root, int &res) {
        if(root == NULL){
            return 0;
        }
        int h1 = maxHeight(root->left,res);
        int h2 = maxHeight(root->right,res);
        res = max(res,h1+h2);
        return 1 + max(h1,h2);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        int mH  = maxHeight(root,res);
        return res;
    }
};
