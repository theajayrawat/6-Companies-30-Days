// https://leetcode.com/problems/image-smoother/
// TC: O(N*M)
// SC: O(1)

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        // Y = p * 256 + r
        // original == Y%256
        // modified == Y/256

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int count = 0;

                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (0 <= x && x < m && 0 <= y && y < n) {
                            sum += img[x][y] % 256;
                            count += 1;
                        }
                    }
                }
                img[i][j] += (sum / count) * 256;
            }
        }


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                img[i][j] /= 256;
            }
        }


        return img;
    }
};