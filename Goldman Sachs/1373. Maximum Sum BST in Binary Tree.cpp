// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
// TC: O(N)
// SC: O(1)

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
class BST{
    public:
    int sum;
    bool isBST;
    int maxi;
    int mini;

};
class Solution {
public:
    BST solve(TreeNode* root, int &maxSum){
        if(!root){
            return {0,true,INT_MIN,INT_MAX};
        }

        BST left=solve(root->left,maxSum);
        BST right=solve(root->right,maxSum);

        BST tree;

        tree.sum=left.sum+right.sum+root->val;
        tree.maxi=max(root->val,right.maxi);
        tree.mini=min(root->val,left.mini);
        if(left.isBST && right.isBST && root->val>left.maxi && root->val<right.mini){
            tree.isBST=true;
        }else{
            tree.isBST=false;
        }

        if(tree.isBST){
            maxSum=max(maxSum,tree.sum);
        }

        return tree;
        
    }
    int maxSumBST(TreeNode* root) {
        int maxSum=0;
        BST tree=solve(root,maxSum);
        return maxSum;
    }
};

