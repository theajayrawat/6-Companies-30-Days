// https://leetcode.com/problems/matrix-cells-in-distance-order/
// T.C : O(N*M) 
// S.C : O(N*M)

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<pair<int,pair<int,int>>>v;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int d=abs(i- rCenter) + abs(j - cCenter);
                v.push_back(make_pair(d,make_pair(i,j)));
            }
        }
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        for(int i=0;i<v.size();i++){
            ans.push_back({v[i].second.first,v[i].second.second});
        }
        return ans;
    }
};
