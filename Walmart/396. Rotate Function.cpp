// https://leetcode.com/problems/rotate-function/
// TC: O(N)
// SC: O(N) 

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        int totalSum=0;
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(i*nums[i]);
            totalSum+=nums[i];
        }


        vector<int>dp(n,0);
        dp[0]=sum;
        int ans=sum;
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1]+totalSum-n*nums[n-i];
            ans=max(ans,dp[i]);
        }

        return ans;
    }
};