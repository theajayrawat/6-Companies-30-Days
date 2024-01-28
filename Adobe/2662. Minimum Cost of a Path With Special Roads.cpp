// https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/
// TC: O((V+E)*logV)
// SC: O(V)

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {

        set<vector<int>>points;
        map<vector<int>,int> distance;
        map<vector<int>,int> specialDis;
         
        points.insert(start);   
        distance[start]=INT_MAX;
        points.insert(target); 
        distance[target]=INT_MAX;
        
        
        for(int i=0;i<specialRoads.size();++i){
            
            int x1=specialRoads[i][0];
            int y1=specialRoads[i][1];
            int x2=specialRoads[i][2];
            int y2=specialRoads[i][3];
            int dis=specialRoads[i][4];
            
            points.insert({x1,y1});
            points.insert({x2,y2});
            
            if(specialDis.find({x1,y1,x2,y2})==specialDis.end())             
            specialDis[{x1,y1,x2,y2}]=dis;
            else
            specialDis[{x1,y1,x2,y2}]=min(specialDis[{x1,y1,x2,y2}],dis);
                
            distance[{x1,y1}]=INT_MAX;
            distance[{x2,y2}]=INT_MAX;       
        }
        
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> q;
        q.push({0,start[0],start[1]});
        
        while(!q.empty()){
              
            vector<int> u=q.top(); q.pop();
            int x1=u[1];
            int y1=u[2];
            int curr_dis=u[0];
        
            if(x1==target[0] && y1==target[1]) return curr_dis;
            
            for(auto itr=points.begin();itr!=points.end();itr++){
                
                vector<int> v=(*itr);
                if(u==v) continue;
                
                int x2=v[0];
                int y2=v[1];
                int cost1=(abs(x2-x1) + abs(y2-y1)); 
                int cost2=INT_MAX;
                
                // checking is this any special road
                if(specialDis.find({x1,y1,x2,y2})!=specialDis.end()){
                   cost2=specialDis[{x1,y1,x2,y2}];
                }
                
                int weight=min(cost1,cost2);
                 
                if(curr_dis + weight < distance[{x2,y2}] ){ 
                    distance[{x2,y2}]=curr_dis + weight;
                    q.push({distance[{x2,y2}],x2,y2});
                }                 
            }
         }
        
        return 0;
    }
};