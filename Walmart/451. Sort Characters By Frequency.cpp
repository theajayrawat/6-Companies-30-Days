// https://leetcode.com/problems/sort-characters-by-frequency/
// SC: O(N)
// TC: O(N) 

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

       vector<pair<int,char>>v;
       for(auto &i:mp){
           v.push_back(make_pair(i.second,i.first));
       }

       sort(v.begin(),v.end());

        string str="";
       for(int i=v.size()-1;i>=0;i--){
           int val=v[i].second;
           int freq=v[i].first;
           while(freq){
               str+=val;
               freq--;
           }
       }

       return str;

    }
};