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
    bool sameTree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL and subRoot == NULL){
            return true;
        }
        else if(root && subRoot && root-> val == subRoot->val){
            return sameTree(root->left, subRoot->left) and sameTree(root->right, subRoot->right);
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL){
            return false;
        }
        if(subRoot == NULL){
            return false;
        }
        if (sameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};
