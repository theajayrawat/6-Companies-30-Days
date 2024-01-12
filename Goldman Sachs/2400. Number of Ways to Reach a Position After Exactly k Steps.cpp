// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/
// TC: O(2^N)
// SC: O(N^2)

class Solution {
public:
    int n;
    int t[3001][1001];
    int MOD = 1e9+7;
    int solve(int startPos, int endPos, int k) {
        if(startPos == endPos && k==0) {
            return 1;
        }
        if(k==0 ||  abs(endPos - startPos)>k)
            return 0;
        
        if(t[startPos+1000][k] != -1)
            return t[startPos+1000][k];
        
        int result = solve(startPos-1,endPos, k-1) % MOD; //RIGHT

        result = (result + solve(startPos+1,endPos, k-1)) % MOD; //LEFT
        
        return t[startPos+1000][k] = result;
        
    }
    int numberOfWays(int startPos, int endPos, int k) {
        int diff = abs(endPos - startPos);
        if (diff > k)
             return 0;
      
        memset(t, -1, sizeof(t));
        return solve(startPos,endPos, k);
    }
};