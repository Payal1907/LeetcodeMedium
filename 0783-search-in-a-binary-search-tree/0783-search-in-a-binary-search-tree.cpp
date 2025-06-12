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
 //this is iterative approach to solve it
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL && root->val!=val)
        {
            root=val>root->val?root->right:root->left;
        }
        return root;
    }
};