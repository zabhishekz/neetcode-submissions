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
    void kthlevel(TreeNode* root, int k, vector<int> &res){
        if(root == NULL){
            return;
        }
        if(k == 1){
            res.push_back(root->val);
            return;
        }
        kthlevel(root->left, k-1, res);
        kthlevel(root->right, k-1, res);
    }
    int heightofbinaryTree(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1 + max(heightofbinaryTree(root->left), heightofbinaryTree(root->right));
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> final;
        int height = heightofbinaryTree(root);
        for(int k = 1; k <= height; k++){
            vector<int> res;
            kthlevel(root, k,res);
            final.push_back(res);
        }
        return final;
    }
};
