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
 unordered_map<int,int> m;
    int i;
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post,int l,int r)
    {
        if(l>r)
            return NULL;
        
        TreeNode *root=new TreeNode(post[i]);
        int mid=m[post[i]];
        i--;
        
        root->right=buildTree(in,post,mid+1,r);
        root->left=buildTree(in,post,l,mid-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        
        int j,n=in.size();
        for(j=0;j<n;j++)
            m[in[j]]=j;
        
        i=n-1;
        return buildTree(in,post,0,n-1);
    }
};
