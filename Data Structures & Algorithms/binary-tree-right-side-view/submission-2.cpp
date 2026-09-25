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
        queue<TreeNode*> q;
        if(root) q.push(root);

        while(!q.empty()){
            int s = q.size();
            for(int i = 0; i < s-1; i++){
                TreeNode* t = q.front(); q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }

            TreeNode* ri = q.front(); q.pop();
            res.push_back(ri->val);

            if(ri->left) q.push(ri->left);
            if(ri->right) q.push(ri->right);
        }

        return res;
    }
};
