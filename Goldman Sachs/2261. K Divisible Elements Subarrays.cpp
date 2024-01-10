// https://leetcode.com/problems/k-divisible-elements-subarrays
// TC: O(N^2*logN) 
// SC: O(N^2)

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        vector<int>pre(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]%p==0 && nums[i]>=p){
                pre[i]=++cnt;
            }else{
                pre[i]=cnt;
            }
        }

        int ans=0;
        set<string>st;
        for(int i=0;i<n;i++){
            string str;
            for(int j=i;j<n;j++){
                if(i==0 && pre[j]>k){
                    break;
                }
                else if(i>0 && abs(pre[j]-pre[i-1])>k){
                    break;
                } 
                str+=to_string(nums[j])+"$";    
                st.insert(str);
            }
        }

        return st.size();
    }


};