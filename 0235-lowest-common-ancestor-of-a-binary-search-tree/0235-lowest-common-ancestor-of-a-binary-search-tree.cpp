/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return NULL;
    if(root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left,p,q); 
    //agr dono chote hai to left subtree me honge descendants
    if(root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right,p,q); 
    //agr dono bde hai to right subtree
    return root;  
    //equal case possible nai, agr koi bhi greater ya less than hua to root hi hoga LCA
    }
};