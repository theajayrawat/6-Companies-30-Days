// https://leetcode.com/problems/top-k-frequent-words/
// TC: O(NLogN)
// SC: O(N) 

class Solution {
public:
    static bool cmp(pair<string,int>&a, pair<string,int>&b){
        if(a.second!=b.second){
            return a.second>b.second;
        }

        return a.first<b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }

        vector<pair<string,int>>v;

        for(auto &i:mp){
            v.push_back(make_pair(i.first,i.second));
        }

        sort(v.begin(),v.end(),cmp);

        vector<string>ans;
        for(int i=0;i<v.size();i++){
            if(k==0)
                break;
            ans.push_back(v[i].first);
            k--;
        }


        return ans;
    }
};