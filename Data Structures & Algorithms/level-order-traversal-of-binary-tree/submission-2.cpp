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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int qLen = q.size();
            vector<int> level;
            while(qLen != 0){
                TreeNode* f = q.front();
                q.pop();
                level.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                qLen--;
            }
            res.push_back(level);
        }
        return res;
    }
};
