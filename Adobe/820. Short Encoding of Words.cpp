// https://leetcode.com/problems/short-encoding-of-words/
// T.C : O(N*w) "w size of average word"
// S.C : O(N*w)

class TrieNode {
public:
    TrieNode() : children(26, nullptr), count(0) {}

    TrieNode* get(char c) {
        if (children[c - 'a'] == nullptr) {
            children[c - 'a'] = new TrieNode();
            count++;
        }
        return children[c - 'a'];
    }

    vector<TrieNode*> children;
    int count;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* trie = new TrieNode();
        unordered_map<TrieNode*, int> nodes;

        for (int i = 0; i < words.size(); ++i) {
            string word = words[i];
            TrieNode* cur = trie;
            for (int j = word.length() - 1; j >= 0; --j)
                cur = cur->get(word[j]);
            nodes[cur] = i;
        }

        int ans = 0;
        for (auto& entry : nodes) {
            TrieNode* node = entry.first;
            if (node->count == 0)
                ans += words[entry.second].length() + 1;
        }
        return ans;
    }
};
