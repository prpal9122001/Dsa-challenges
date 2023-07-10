//https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
class Solution{
    public:
    int minDepth(TreeNode* root){
        if(!root)
        return NULL;
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        if(left==0||right==0){
            return(1+right+left);
        }else{
            return 1+min(left,right);
        }
    }
