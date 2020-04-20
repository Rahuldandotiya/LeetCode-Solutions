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
    int i=0;
    TreeNode *insert(vector<int>& pre,int max=INT_MAX){
        if(i>=pre.size() or pre[i]>max) return NULL;
        TreeNode* root=new TreeNode(pre[i]);
        int l=pre[i];
        i++;
        root->left=insert(pre,l);
        root->right=insert(pre,max);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        return insert(pre);
    }
};
