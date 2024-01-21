// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
// TC: O(NlogN)
// SC: O(N) 

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        int t=0;
        for(int i=0;i<n;i++){
            t+=nums[i];
        }
        if(k==n)
            return nums;

        priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        for(int i=0;i<n;i++){
            if(q.size()==k){
                if(q.top()[0]<nums[i]){
                    q.pop();
                    q.push({nums[i],i});
                }

            }else
                q.push({nums[i],i});
        }

        vector<vector<int>> res;
        while(!q.empty()){
            int val=q.top()[0];
            int index=q.top()[1];
            res.push_back({index,val});
            q.pop();
        }

        sort(res.begin(),res.end());

        vector<int>ans;
        for(int i=0;i<res.size();i++){
            ans.push_back(res[i][1]);
        }

        return ans;


    }
};
