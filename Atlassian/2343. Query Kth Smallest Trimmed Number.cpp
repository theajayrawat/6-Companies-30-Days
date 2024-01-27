// https://leetcode.com/problems/query-kth-smallest-trimmed-number/
// TC: O(NlogN)
// SC: O(N)

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>v;
        int n=nums[0].size();
        vector<pair<string,int>>p;
         for(int j=0;j<nums.size();j++){
            p.push_back(make_pair(nums[j],j));
        }
        sort(p.begin(),p.end());
        for(int i=0;i<queries.size();i++){
            int trim=queries[i][1];
            int index=queries[i][0];
            vector<string>temp;
            if(trim<n){
                vector<pair<string,int>>temp;
                for(int j=0;j<nums.size();j++){
                    string newVal= nums[j].substr(n-trim);
                    temp.push_back(make_pair(newVal,j));
                }
                sort(temp.begin(),temp.end());
                v.push_back(temp[index-1].second);
            }else{
                v.push_back(p[index-1].second);
            }  
        }

        return v;
    }
};

