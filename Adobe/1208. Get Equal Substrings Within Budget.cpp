// https://leetcode.com/problems/get-equal-substrings-within-budget/
// T.C : O(N)
// S.C : O(N)

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int left=0;
        int currSum=0;
        int ans=0;
       for(int right=0;right<n;right++){
            currSum+=abs(s[right] - t[right]);
            while(left<=right && currSum>maxCost){
                currSum-=abs(s[left] - t[left]);
                left++;
            }
            ans=max(ans,right-left+1);
       }

       return ans;
    }
};