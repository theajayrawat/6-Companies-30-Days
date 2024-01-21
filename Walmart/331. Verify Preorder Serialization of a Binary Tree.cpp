// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
// TC: O(N)
// SC: O(1) 

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string temp;
        int vacancy=1;
        while(getline(ss,temp,',')){
            vacancy--;
            if(vacancy<0)
                return false;
            if(temp!="#")
                vacancy+=2;
        }

        return vacancy==0;
    }
};