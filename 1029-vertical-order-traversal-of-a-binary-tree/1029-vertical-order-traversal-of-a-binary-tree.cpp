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
    int maxHeight(TreeNode* root)
    {
        if(root==NULL) return 0;
        int lh=maxHeight(root->left);
        int rh=maxHeight(root->right);
        return 1+max(lh,rh);
    }
    int maxDiameter(TreeNode* root,int& breadth)
    {
        if(root==NULL) return 0;
        int lh=maxHeight(root->left);
        int rh=maxHeight(root->right);
        breadth=max(breadth,lh+rh);
        return 1+max(lh,rh);
    }
    void assign(TreeNode* root,unordered_map<TreeNode*,pair<int,int>>& mp,int row, int col)
    {
        if (root == NULL) return;
        mp[root] = {row, col};
        assign(root->left, mp, row + 1, col - 1);
        assign(root->right, mp, row + 1, col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    int breadth = 0;
    maxDiameter(root,breadth);   
    int length = maxHeight(root);
    unordered_map<TreeNode*,pair<int,int>> mp;
    assign(root, mp, 0, 0);
    map<int, multiset<pair<int, int>>> verticals;

        for (auto& [node, pos] : mp) {
            int row = pos.first;
            int col = pos.second;
            verticals[col].insert({row, node->val});
        }

        for (auto& [col, nodes] : verticals) {
            vector<int> current;
            for (auto& [row, val] : nodes)
                current.push_back(val);
            ans.push_back(current);
        }
    return ans;
    }
};