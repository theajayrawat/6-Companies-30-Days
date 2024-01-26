// https://leetcode.com/problems/constrained-subsequence-sum/
// T.C : O(N) 
// S.C : O(N)

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        heap.push({nums[0], 0});
        int ans = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            while (i - heap.top().second > k) {
                heap.pop();
            }

            int curr = max(0, heap.top().first) + nums[i];
            ans = max(ans, curr);
            heap.push({curr, i});
        }
        
        return ans;
    }
};