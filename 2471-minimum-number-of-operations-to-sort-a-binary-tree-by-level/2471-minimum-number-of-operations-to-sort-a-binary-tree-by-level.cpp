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
    int minOps(vector<int>& level){
        int swaps = 0;
        int n = level.size();
        vector<pair<int,int>> mp;
        for(int i=0;i<n;i++){
            mp.push_back({level[i],i});
        }
        sort(mp.begin(),mp.end());
        for(int i=0;i<n;i++){
            if(mp[i].first!=level[i]){
                swap(mp[mp[i].second],mp[i]);
                i--;
                swaps++;
            }
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
    int mn = 0;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        vector<int> level;
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    mn+=minOps(level);    
    }   
    return mn; 
    }
};