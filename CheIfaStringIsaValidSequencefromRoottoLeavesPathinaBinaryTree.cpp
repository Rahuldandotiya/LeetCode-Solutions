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
    bool check(TreeNode* root, vector<int>& arr,int i){
        if(root==NULL) return (arr.size()==0);
        if(root->left==NULL && root->right==NULL && i<arr.size() && root->val==arr[i] && i==arr.size()-1) return true;
        return ((arr.size()>i) && (root->val==arr[i]) && (check(root->left,arr,i+1) || check(root->right,arr,i+1)));
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        int i=0;
        return check(root,arr,i);
    }
};
