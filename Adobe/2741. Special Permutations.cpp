// https://leetcode.com/problems/special-permutations/
// T.C : O(N)
// S.C : O(2^N)

class Solution {
public:
    int dp[16385][16];
    int mod = 1e9 + 7;
    int solve(vector<int>& nums,int mask,int i,int cnt){
        if(cnt==nums.size())
            return 1;
        if (dp[mask][i + 1] != -1)
            return dp[mask][i + 1];

        int res = 0;
        for (int j = 0; j < nums.size(); j++)
            if (i == -1 || ((mask & (1 << j)) == 0 && i != j && (nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0)))
                (res += solve(nums, mask | (1 << j), j, cnt + 1))%= mod;
        return dp[mask][i + 1] = res;
    }
    int specialPerm(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1,0);
    }
};