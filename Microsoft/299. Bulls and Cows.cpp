// https://leetcode.com/problems/bulls-and-cows/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>mp;
        int n=secret.size();
        int bulls=0,cows=0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i])
                bulls++;
            else
                mp[secret[i]]++;
        }

        for(int i=0;i<n;i++){
            if(mp.find(guess[i])!=mp.end() && secret[i]!=guess[i]){
                mp[guess[i]]--;
                cows++;
                if(mp[guess[i]]==0){
                    mp.erase(guess[i]);
                }
            }
        }

        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};

