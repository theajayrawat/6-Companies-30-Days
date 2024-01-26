// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
// T.C : O(N*w)
// S.C : O(N*w)

class Solution {
public:
    bool isSubsequence(const string& s, const string& word) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) {
                j++;
            }
            i++;
        }
        return j == word.size();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        int maxLen = 0;

        for (const string& word : dictionary) {
            if (word.size() < maxLen || word.size() > s.size()) {
                // Skip words that can't be longer than the current maxLen or are longer than s
                continue;
            }

            if (isSubsequence(s, word)) {
                if (word.size() > maxLen || (word.size() == maxLen && word < ans)) {
                    ans = word;
                    maxLen = word.size();
                }
            }
        }

        return ans;
    }
};
