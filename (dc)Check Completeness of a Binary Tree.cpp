//https://leetcode.com/problems/check-completeness-of-a-binary-tree/description/

class Solution {
public:
    bool isCompleteTree(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node= q.front();      //front() method returns the next element within the queue
            q.pop();
            if(node!= NULL)
            {
                q.push(node->left);
                q.push(node->right);
            }
            else
            {
                if(!q.empty() && q.front()!= NULL)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
