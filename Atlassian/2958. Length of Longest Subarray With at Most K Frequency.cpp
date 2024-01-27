// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int cnt=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]>=k){
                break;
            }
            mp[nums[i]]++;
            cnt++;
        }
        
        if(cnt==n)
            return n;
        int ans=cnt;
        int i=0;
        for(int j=cnt;j<n;j++){
            while(mp[nums[j]]>=k){
                mp[nums[i]]--;
                    i++;
            }
            mp[nums[j]]++;
            ans=max(ans,j-i+1);
        }
        
        return ans;
    }
};

