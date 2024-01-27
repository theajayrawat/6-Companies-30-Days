// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/
// TC: O(NLogN)
// SC: O(N)
class Solution {
public:
     void compute( vector<int>&lps, string pat, int m){
            int len=0;
            lps[0]=0;
            int i=1;
            while(i<m){
               if(pat[i]==pat[len]){
                   len++;
                   lps[i]=len;
                   i++;
               }else{
                   if(len!=0){
                       len=lps[len-1];
                   }else{
                       lps[i]=0;
                       i++;
                   }
               }
            }
            
        }
        vector <int> search(string pat, string txt)
        {
            //code hee.
            int m=pat.size();
            int n=txt.size();
            vector<int>lps(m,0);
            compute(lps,pat,m);
            
             vector<int> result;
             
            int i = 0; 
            int j = 0; 
            
            while(i<n){
                if(pat[j]==txt[i]){
                    i++;
                    j++;
                }
                if(j==m){
                    result.push_back(i-j);
                    j = lps[j - 1];
                }else if(i<n && pat[j] != txt[i]){
                    if(j!=0){
                        j=lps[j-1];
                    }else{
                        i++;
                    }
                }
            }
            
            return result;
        }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>A=search(a,s);
        vector<int>B=search(b,s);
        if(A.size()==0 || B.size()==0)
            return {};
            
        vector<int>ans;
        for(int i=0;i<A.size();i++){
            //j<=k+i
            int val=k+A[i];
            int j=lower_bound(B.begin(),B.end(),val)-B.begin();
            if(j>=B.size() || B[j]!=val)
                j--;
                
            if(j<B.size() && abs(B[j]-A[i])<=k){
                ans.push_back(A[i]); 
            }
            
        }
        
        return ans;
        
    }
};