/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int find(TreeNode* root,int &ans){
        if(root==NULL) return 0;
        int ls=find(root->left,ans);
        int rs=find(root->right,ans);
        int maxx=max(max(ls,rs)+root->val,root->val);
        int maxx2=max(maxx,ls+rs+root->val);
        ans=max(ans,maxx2);
        return maxx;
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        find(root,ans);
        return ans;
    }
};
