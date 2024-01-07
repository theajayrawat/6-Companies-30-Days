// https://leetcode.com/problems/random-flip-matrix/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    set<vector<int>>setValue;
    int m,n;
    Solution(int m, int n) {
      this->m=m;
      this->n=n;
    }
    
    vector<int> flip() {
        int i=rand() % m;
        int j=rand() % n;
        while(setValue.count({i,j})){
            i=rand() % m;
            j=rand() % n;
        }

        setValue.insert({i,j});
        return {i,j};

    }
    
    void reset() {
        setValue.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */