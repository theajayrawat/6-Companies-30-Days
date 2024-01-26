// https://leetcode.com/problems/cinema-seat-allocation/
// T.C : O(N)
// S.C : O(N)

class Solution {
public:
    int solve(const unordered_set<int>& s) {
        if (!(s.count(2) || s.count(3) || s.count(4) || s.count(5)) &&
            !(s.count(6) || s.count(7) || s.count(8) || s.count(9))) {
               return 2;
        } else if(!(s.count(2) || s.count(3) || s.count(4) || s.count(5)) ||
            !(s.count(6) || s.count(7) || s.count(8) || s.count(9))) {
               return 1;
        }else if (!(s.count(4) || s.count(5) || s.count(6) || s.count(7))) {
            return 1;
        }
        return 0;
    }

    int maxNumberOfFamilies(int n, const vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> st;
        for (const auto& seat : reservedSeats) {
            st[seat[0]].insert(seat[1]);
        }

        int ans = 0;
        for (const auto& row : st) {
            ans += solve(row.second);
        }

        // For each row without any reserved seats, you can add 2 families.
        ans += 2 * (n - st.size());
        
        return ans;
    }
};
