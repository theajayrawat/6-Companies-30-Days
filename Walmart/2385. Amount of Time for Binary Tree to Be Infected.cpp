// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
// SC: O(N)
// TC: O(N) 

class Solution {
public:
        int result = INT_MIN;

    int solve(TreeNode* root, int start) {
        if(root == NULL) {
            return 0;
        }

        int LH = solve(root->left, start);
        int RH = solve(root->right, start);

        if(root->val == start) {
            result = max(LH, RH);
            return -1; // return -1 for start node
        } else if(LH >= 0 && RH >= 0) {
            return max(LH, RH) + 1;
        } else {
            int d = abs(LH) + abs(RH);
            result = max(result, d);

            return min(LH, RH) - 1; //return negative value with addition of -1
        }

        return 0;
    }

    int amountOfTime(TreeNode* root, int start) {
        solve(root, start);

        return result;
    }
};
