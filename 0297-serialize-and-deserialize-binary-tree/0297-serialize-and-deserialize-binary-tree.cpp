/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "null,";
        queue<TreeNode*> q;
        q.push(root);
        string res="";
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node)
                {
                    res+=to_string(node->val)+",";
                    q.push(node->left);
                    q.push(node->right);
                }
                else res+="null,";
            }
        }
        if (!res.empty() && res.back() == ',') res.pop_back();
        return res;    
    }
    vector<string> split(string data, char delimiter)
    {
        vector<string> nodes;
        stringstream ss(data);
        string token;
        while(getline(ss,token,delimiter))
        {
            if(!token.empty()) nodes.push_back(token); 
            //condition lgaya kyuki stoi will not be able to convert empty string
        }
        return nodes;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty() || data=="null"||data=="null,") return nullptr;
        vector<string> nodes = split(data,',');
        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(!q.empty() && i<nodes.size())
        {
            TreeNode* curr = q.front();
            q.pop();

            //left child dhoondhenge
            if(i<nodes.size() && nodes[i]!="null")
            {
                curr->left=new TreeNode(stoi(nodes[i]));
                q.push(curr->left);
            }
            i++;
            if(i<nodes.size() && nodes[i]!="null")
            {
                curr->right=new TreeNode(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;
        }
        return root;
           
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));