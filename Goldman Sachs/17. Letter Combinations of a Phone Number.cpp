// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// TC: O(N^4)
// SC: O(N^4)

class Solution {
public:
    void solve(string digits, int index, vector<string>&v, vector<string>&ans, string s){
        if(index==digits.size()){
            ans.push_back(s);
            return;
        }
        int i=digits[index]-'0';

        for(int j=0;j<v[i].size();j++){
            solve(digits,index+1,v,ans,s+v[i][j]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        if(digits.size()==0)
            return ans;
        solve(digits,0,v,ans,"");
        return ans;
    }
};