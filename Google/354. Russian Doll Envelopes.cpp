// https://leetcode.com/problems/russian-doll-envelopes/
// TC: O(N^2*logN)
// SC: O(N)

class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        
        return a[1]>b[1];
    }

    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;

        vector<int>ans;
        ans.push_back(nums[0]);        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>ans.back())
                ans.push_back(nums[i]);
            else
            {
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }

        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comp);

        vector<int>nums;
        for(auto i:envelopes)
            nums.push_back(i[1]);
        return lengthOfLIS(nums);
    }
};