// https://leetcode.com/problems/trim-a-binary-search-tree/
// T.C : O(N)
// S.C : O(N)

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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
            return root;
        
        if(root->val<low){
            root==NULL;
            return root->right=trimBST(root->right,low,high);
        }
        else if(root->val>high){
            root==NULL;
            return root->left=trimBST(root->left,low,high);
        }
        else {
            root->left=trimBST(root->left,low,high);
            root->right=trimBST(root->right,low,high);
            return root;
        }
        
    }
};