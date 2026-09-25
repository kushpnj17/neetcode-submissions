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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        if(root) q.push(root);

        while(!q.empty()){
            auto p = q.front(); q.pop();

            if(p->val == subRoot->val){
                if(isSameTree(p, subRoot)) return true;
            }

            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }

        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) {
            return true;
        } else if (!p || !q){
            return false;
        }

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
