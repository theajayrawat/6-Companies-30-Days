// https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1
// TC: O(N)
// SC: O(1)

class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int num=1;
        stack<int>s;
        string result;
        for(int i=0;i<S.size();i++){
            s.push(num++);
            if(S[i]=='I'){
                while(!s.empty()){
                    result+=to_string(s.top());
                    s.pop();
                }
            }
        }
        
        s.push(num++);
            while(!s.empty()){
                result+=to_string(s.top());
                s.pop();
        }
        
        return result;
    }
};