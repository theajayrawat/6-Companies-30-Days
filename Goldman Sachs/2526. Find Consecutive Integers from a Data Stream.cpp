// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/
// TC: O(K)
// SC: O(K)

class DataStream {
public:
    queue<int>q;
    unordered_map<int,int>mp;
    int val,k;
    DataStream(int value, int k) {
        this->val=value;
        this->k=k;
    }
    
    bool consec(int num) {
        q.push(num);
        mp[num]++;
        bool ans = mp.size() == 1 && q.size() == k && num == val;
        if(q.size()==k){
            int n=q.front();
            q.pop();
            mp[n]--;
            if(mp[n]==0)
                mp.erase(n);       
        }

        return ans;
    }
};