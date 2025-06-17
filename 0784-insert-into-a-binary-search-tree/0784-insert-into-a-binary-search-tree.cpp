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
//copy is a pointer that points to the same node as root, so agr tu copy me changes kregi to root me bhi changes honge, aur is question ka logic ye hai ki insert krne ke bhot tarike hote hai pr sabse easy tarika hai ki tu koi bhi leaf node dhoondh ke uspr insert krde
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* copy = root;
        while(true)
        {
            if(val>=copy->val)
            {
                if(copy->right) copy=copy->right;
                else
                {
                    copy->right=new TreeNode(val);
                    break;
                }
            }
            else
            {
                if(copy->left) copy=copy->left;
                else
                    {
                        copy->left=new TreeNode(val);
                        break;
                    }
            }
        }
        return root;
        
    }
};