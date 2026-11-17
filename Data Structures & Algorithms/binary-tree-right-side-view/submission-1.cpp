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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int qLen = q.size();
            while(qLen != 1){
                TreeNode* f = q.front();
                q.pop();
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                qLen--;
            }
            TreeNode* f = q.front();
            q.pop();
            res.push_back(f->val);
            if (f->left) q.push(f->left);   // Don't forget its children!
            if (f->right) q.push(f->right);
        }
        return res;
    }
};
