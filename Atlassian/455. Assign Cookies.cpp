// https://leetcode.com/problems/assign-cookies/
// TC: O(NLogN)
// SC: O(1)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int j=0;
        int n=s.size();
        int m=g.size();
        int cnt=0;

        for(int i=0;i<m;i++){
            while(j<n && s[j] < g[i]){
                j++;
            }
            if(j==n)
                break;

            cnt++;
            j++;
        }

        return cnt;
    }
};