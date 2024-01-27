// https://leetcode.com/problems/design-add-and-search-words-data-structure/
// TC: O(N^25)
// SC: O(1)

class WordDictionary {
public:
    unordered_map<string,int>mp;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word]++;
    }
    bool solve(string word, int k){
        if(mp.find(word)!=mp.end())
            return true;
        if(word.find('.')==string::npos)   
            return false;

        bool ans=false;
        for(int i=k;i<word.size();i++){
            if(word[i]=='.'){
                for(int j='a';j<='z';j++){
                    word[i]=j;
                    ans|=solve(word,i+1);
                    if(ans)
                        return ans;
                }
            }
        }

        return ans;  
    }
    bool search(string word) {
        return solve(word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */