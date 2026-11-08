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
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL and subRoot == NULL){
            return true;
        }
        else if(root && subRoot && root-> val == subRoot->val){
            return isSameTree(root->left, subRoot->left) and isSameTree(root->right, subRoot->right);
        }
        return false;
    }
};
