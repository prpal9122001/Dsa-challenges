//https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/915109954/

class Solution {
    public:
        int sum(TreeNode *root,int back)
        {
            if(root==NULL)
               return 0;
            else
            {
                int newback=back*10+root->val;
                if(root->left==NULL&&root->right==NULL)
                    return newback;
                else
                    return sum(root->left,newback)+sum(root->right,newback);
            }
        }
        int sumNumbers(TreeNode* root) {
            if(root==NULL)
              return 0;
            return sum(root,0);
        }
    };
