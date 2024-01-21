// https://leetcode.com/problems/count-the-number-of-square-free-subsets/
// TC: O(2^m) -- where m = size of valid unique array <= 19
// SC: O(30) 

class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1ll;

        while (b) {
            if (b % 2) {
                res *= a;
                res %= MOD;
            }
            b >>= 1ll;
            a *= a;
            a %= MOD;
        }
        return res;
    }

    int squareFreeSubsets(std::vector<int>& nums) {
        vector<int>not_allowed(31,0);
        for (int i = 2; i <= 5; ++i) {
            int cur = i * i;
            for (int j = cur; j < 31; j += cur) {
                not_allowed[j]++; //removing square element
            }
        }


        vector<long long> z;
        vector<long long> fre(31);
        for (auto& x : nums) {
            fre[x]++; //add frequency
            if (not_allowed[x] == 0) {
                z.push_back(x); //push allowed element
                not_allowed[x]++; // not push repeat element
            }
        }

        // corner case, "1"" is allowed
        long long ex = 1;
        if (not_allowed[1]) {
            ex = power(2ll, fre[1]) - 1;
        }

        int n = z.size();
        long long ans = 0;
        int lim = (1 << n);

        for (int i = 1; i < lim; ++i) {
            long long pro = 1, gc = 1, val = 1, e = 1;

            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    gc = __gcd(pro, z[j]); 
                    if (gc > 1) { //gcd is not one so square can from 
                        break;
                    }

                    pro *= z[j];
                    if (z[j] != 1) {
                        val *= fre[z[j]];
                        val %= MOD;
                    } else {
                        e = ex;
                    }
                }
            }

            if (gc == 1) {
                val *= e;
                val %= MOD;
                ans += val;
                ans %= MOD;
            }
        }

        return (int)(ans);
    }
};


