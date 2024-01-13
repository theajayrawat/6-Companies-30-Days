// https://leetcode.com/problems/wiggle-sort-ii/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int>v=nums;
        sort(v.begin(),v.end());

        int j=n-1;
        for(int i=1;i<n;i+=2)
        {
            nums[i]=v[j];
            j--;
        }

        for(int i=0;i<n;i+=2)
        {
            nums[i]=v[j];
            j--;
        }

    }
};