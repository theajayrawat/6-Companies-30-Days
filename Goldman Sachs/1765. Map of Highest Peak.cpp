// https://leetcode.com/problems/map-of-highest-peak/
// TC: O(N*M)
// SC: O(1)

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push(make_pair(i,j));
                    isWater[i][j]=0;
                }else{
                    isWater[i][j]=-1;
                }
                    
            }
        }

        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        while(!q.empty()){
            int qSize=q.size();
            while(qSize){
                pair<int,int>p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                for(int k=0;k<4;k++){
                    int i=x+dx[k];
                    int j=y+dy[k];
                    if(i>=0 && j>=0 && i<n && j<m && isWater[i][j]==-1){
                        isWater[i][j]=isWater[x][y]+1;
                        q.push(make_pair(i,j));
                    }
                }
                qSize--;
            }
            
        }

        return isWater;
    }
};



