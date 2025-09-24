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
    unordered_map<int,vector<int>> connections;
    //hr node kis kis node se connected hai wo check krenge
    void findConnections(TreeNode* root)
    {
        if(!root) return;
        if(root->left)
        {
            connections[root->val].push_back(root->left->val);
            connections[root->left->val].push_back(root->val);
        }
        if(root->right)
        {
            connections[root->val].push_back(root->right->val);
            connections[root->right->val].push_back(root->val);
        }
        findConnections(root->left);
        findConnections(root->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        findConnections(root);
        queue<int> q;
        q.push(start);
        unordered_set<int> visited; //set liya kyuki unique chahiye
        int mins = -1;
        //BFS 
        while(!q.empty())
        {
            mins++;
            int size = q.size();
            for(int level = 0;level<size;level++)
            {
                int curr = q.front();
                q.pop();
                visited.insert(curr); //mark visited
                for(auto conn : connections[curr])
                {
                    if(!visited.count(conn)) q.push(conn);
                }
                //hr element jisse connected hai usko queue me push krenge
            } 
        }
        return mins;
    }
};