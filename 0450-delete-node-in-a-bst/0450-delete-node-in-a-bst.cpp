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
 //dekh tu isko do triko se kr skti hai agr easily delete krne hai to, suppose x element hai jo tujhe delete krna
 //hai, to x ke right ko detach krde aur x->left me largest element dhoondhke usi ke right pe insert krde.
 //other way is x ke right ko detach krde aur left ke smallest element pe attach krde
//ek element ke right pe hmesha smaller elements honge aur left pe hmesha greater, code thoda tough hai but
//saare edge cases dekhna dhyaan se, especially null waale
class Solution {
public:
    TreeNode* findLastRight(TreeNode* root)
    {
        if(root->right==NULL) return root;
        return findLastRight(root->right);
    }
    TreeNode* helper(TreeNode* root)
    {
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key) return helper(root);
        TreeNode* dummy = root;
        while(root)
        {
            if(key<root->val)
            {
                if(root->left!=NULL && root->left->val==key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else root = root->left;
            }
            else
            {
                if(root->right!=NULL && root->right->val==key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else root = root->right;
            }
        } 
        return dummy;  
    }
};