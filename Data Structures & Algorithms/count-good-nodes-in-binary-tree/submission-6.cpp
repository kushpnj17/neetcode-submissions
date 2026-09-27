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
    int goodNodes(TreeNode* root) {
        int count = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto p = q.front(); q.pop();
                if(p.first->val >= p.second) {
                    count++;
                    
                    if(p.first->right) q.push({p.first->right, p.first->val});
                    if(p.first->left) q.push({p.first->left, p.first->val});
                } else {
                    if(p.first->right) q.push({p.first->right, p.second});
                    if(p.first->left) q.push({p.first->left, p.second});
                }
            }
        }

        return count;
    }
};
