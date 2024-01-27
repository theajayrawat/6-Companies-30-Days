// https://leetcode.com/problems/repeated-dna-sequences/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //Rabin-Karp Method
        int n=s.size();
        if(n<10) return {};
        vector<int>convert;
        for(int i=0;i<n;i++){
            if(s[i]=='A')
                convert.push_back(1);
            else if(s[i]=='C')
                convert.push_back(2);
            else if(s[i]=='G')
                convert.push_back(3);
            else
                convert.push_back(4);
        }

        unordered_map<long long,int> mp;
        long long hash=0;
        for(int i=0;i<10;i++){
            hash=hash*4+convert[i];
        }
        mp[hash]++;

        vector<string>ans;
        for(int i=1;i<n-9;i++){
            hash=hash*4-convert[i-1]*pow(4,10)+convert[i+9];
            mp[hash]++;
            if(mp[hash]==2) 
                ans.push_back(s.substr(i,10));

        }
        return ans;
    }
};

