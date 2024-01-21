// https://leetcode.com/problems/word-break/
// TC: O(N)
// SC: O(N) 

class Solution {
public:
    bool solve(unordered_map<string,int>&mp, string s, int i, vector<int>&dp){
        if(i==s.size())
            return true;
    
        if(dp[i]!=-1)
            return dp[i];
        bool ans=false;
        for(int j=i;j<s.size();j++){
            string str=s.substr(i,j-i+1);
            if(mp.find(str)!=mp.end()){
                ans|=solve(mp,s,j+1,dp);
            }
        }

        return dp[i]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        vector<int>dp(s.size(),-1);
        for(int i=0;i<wordDict.size();i++){
            mp[wordDict[i]]++;
        }

        return solve(mp,s,0,dp);
    }
};