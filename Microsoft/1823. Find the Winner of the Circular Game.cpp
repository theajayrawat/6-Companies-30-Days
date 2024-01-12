// https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }

        while(q.size()>1){
            int t=k;
            while(q.size()>1){
                t--;
                if(t==0){
                    q.pop();
                    break;
                }else{
                    int val=q.front();
                    q.pop();
                    q.push(val);
                }  
            }
        }

        return q.front();
    }
};