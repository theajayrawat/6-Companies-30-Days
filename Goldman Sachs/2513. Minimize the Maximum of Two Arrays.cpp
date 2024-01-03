// https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/
// TC: O(logN)
// SC: O(1)

#define ll long long
class Solution {
public:
    int gcd(int a, int b) {
        if (!b) return a;
        return gcd(b, a % b);
    }
    int lcm(ll a, ll b) {
        ll temp = (a / gcd(a, b)) * b;
        return temp > INT_MAX ? INT_MAX : temp;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int lo = 1;
        int hi = INT_MAX; 
        int LCM = lcm(divisor1, divisor2);
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int notMutipleOf1=mid-(mid/divisor1);
            int notMutipleOf2=mid-(mid/divisor2);
            if (uniqueCnt1 <= notMutipleOf1 && uniqueCnt2<= notMutipleOf2 && uniqueCnt1 + uniqueCnt2 <= (mid - (mid / LCM))) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};