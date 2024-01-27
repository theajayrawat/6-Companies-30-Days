// https://leetcode.com/problems/construct-the-longest-new-string/
// TC: O(1)
// SC: O(1)

class Solution {
public:
    int longestString(int x, int y, int z) {
       int couple = min(x, y);
        if (x == y) 
            return (couple*2 + z) * 2; // e.g. AA...BB + zAB 
        
        return (couple*2 + 1 + z) * 2; // e.g. AABB...BBAA + z*AB or BBAA..AABB + z*AB 
    }
};