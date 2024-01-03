// https://leetcode.com/problems/high-access-employees/
// TC: O(N)
// SC: O()

class Solution {
public:
    int solve(vector<int>&v){
        int ans=1;

        for(int i=0;i<v.size();i++){
            int currCount=1;
            for(int j=i+1;j<i+3 && j<v.size();j++){
                if(v[j]-v[i]<100)
                    currCount++;
                else
                    break;
            }
            if(currCount==3)
                return true;         
        }
        
        
        return false;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string>ans;
        int n=access_times.size();
        
        unordered_map<string,multiset<int>>mp;
        for(int i=0;i<n;i++){
            mp[access_times[i][0]].insert(stoi(access_times[i][1]));
        }
        
        for(auto &i : mp){
            if(i.second.size()<3)
                continue;
            vector<int>v(i.second.begin(), i.second.end());
            if(solve(v))
                ans.push_back(i.first);
        }
        
        return ans;  
        
    }
};
