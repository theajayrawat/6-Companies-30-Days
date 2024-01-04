// https://leetcode.com/problems/combination-sum-iii/
// TC: O(N^9)
// SC: O(1)

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>v;
        vector<int>temp;
        help(v,temp,1,k,n);
        return v;
    }
    
    void help( vector<vector<int>>&v,vector<int>temp,int i,int k,int n){
       if(k==0&&n==0){
            v.push_back(temp);
            return;
        }      
        else if(k==0||n==0){
            return;
        }
        
        for(int j= i; j <=9; j++){
            temp.push_back(j);
            help(v,temp,j+1,k-1,n-j);
            temp.pop_back();
        }
    }
};