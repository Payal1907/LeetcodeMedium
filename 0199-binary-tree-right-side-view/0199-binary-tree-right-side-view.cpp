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
//last node of every level is there in right view, also if we traverse right to left level wise
// then first node of every level is there in right view
    vector<int> res;
    vector<int> rightSide(TreeNode* root, int level)
    {
        if(root==NULL) return {};
        if(level==res.size()) res.push_back(root->val);
        rightSide(root->right,level+1);
        rightSide(root->left,level+1);
        return res;
    }

    vector<int> rightSideView(TreeNode* root) {
    rightSide(root,0);
    return res;    
    }
};