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
    int maxLevelSum(TreeNode* root) {
        int mx = INT_MIN;
        int sl = 1;
        int lvl = 1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sum = 0;
            int size = q.size(); //since size changes when u insert left and right
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            // cout<<sum<<endl;
            if(sum>mx){
                mx=sum;
                sl=lvl;
                // cout<<"mx sum: "<<mx<<" sml levl: "<<sl<<endl;
                
            }
            lvl++;
        }
        // cout<<mx<<endl;
        return sl;

    }
};