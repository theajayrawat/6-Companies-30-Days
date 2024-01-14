// https://leetcode.com/problems/minimum-cost-to-convert-string-i/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> matrix(26, vector<long long> (26, INT_MAX));
        int n=original.size();
		for (int i=0;i<n;i++) {
            int u = int(original[i] - 'a');
            int v = int(changed[i] - 'a');
            long long w = (long long)cost[i];
            matrix[u][v] = min(w,matrix[u][v]);
		}

        for (int k = 0; k < 26; k++) {
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < 26; j++) {
					if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
						continue;
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				}
			}
		}

		long long result=0;

        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                if(matrix[source[i]-'a'][target[i]-'a']!=INT_MAX)
                result+=matrix[source[i]-'a'][target[i]-'a'];
                else
                    return -1;
            }
        }
		
		return result==0?-1:result;
    }
};