// https://leetcode.com/problems/count-number-of-nice-subarrays/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int sum=0;
        int ans=0;

        for(int i=0;i<n;i++){
            sum+=(nums[i]%2);
            if(sum==k)
                ans++;
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }

        return ans;
    }
};