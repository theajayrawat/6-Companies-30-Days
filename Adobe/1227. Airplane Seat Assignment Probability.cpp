// https://leetcode.com/problems/airplane-seat-assignment-probability/
// T.C : O(1)
// S.C : O(1)

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1)
            return 1.0;
        else 
            return 0.5;
    }
};