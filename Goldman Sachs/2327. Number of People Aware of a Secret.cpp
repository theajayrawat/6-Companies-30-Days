// https://leetcode.com/problems/number-of-people-aware-of-a-secret/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long>dp(n+1,0);
        long m=1e9+7;
        long noOfPeopleShareSecret=0;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            long noOfNewPeopleShareSecret=dp[max(i-delay,0)];
            long noOfNewPeopleForgetSecret=dp[max(i-forget,0)];
            noOfPeopleShareSecret=noOfPeopleShareSecret+noOfNewPeopleShareSecret-noOfNewPeopleForgetSecret;
            dp[i]=noOfPeopleShareSecret%m;
        }

        long ans=0;
		for (int i = n - forget + 1; i <= n; i++) {
			ans = (ans + dp[i]) % m;
		}
		return (int)ans;

    }
};