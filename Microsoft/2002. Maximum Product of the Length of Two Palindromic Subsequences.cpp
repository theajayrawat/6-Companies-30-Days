// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
// TC: O(N^4)
// SC: O(N)

class Solution {
public:
    int result = 0;
    bool isPalin(string& s){
        int i = 0;
        int j = s.length() - 1;
 
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
 
        return true;
    }
    
    void dfs(string& s, int i, string& s1, string& s2){ 
        
        if(i >= s.length()){
            if(isPalin(s1) && isPalin(s2)){
                int val=s1.length()*s2.length();
                result = max(result,val);
            }
               
            return;
        }
        
        s1.push_back(s[i]);
        dfs(s, i+1, s1, s2);
        s1.pop_back();
        
        s2.push_back(s[i]);
        dfs(s, i+1, s1, s2);
        s2.pop_back();
        
        dfs(s, i+1, s1, s2);
    }
    
    int maxProduct(string s) {
        string s1 = "", s2 = "";
        dfs(s, 0, s1, s2);
        
        return result;
    }
};



