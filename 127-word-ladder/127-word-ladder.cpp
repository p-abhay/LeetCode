class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> wordSet;
        for(auto word : wordList)
            wordSet.insert(word);
        if(wordSet.find(endWord) == wordSet.end())
            return 0;
        
        if(wordSet.find(beginWord) != wordSet.end())
            wordSet.erase(beginWord);
        queue<string> q;
        q.push(beginWord);
        
        int ans = 0;
        while(!q.empty())
        {
            ans += 1;
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++) {
                string currWord = q.front();
                q.pop();
                int l = currWord.size();
                for(int j = 0; j < l; j++) {
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        string newWord = currWord.substr(0,j) + ch + currWord.substr(j + 1, l - j - 1);
                        if(wordSet.find(newWord) != wordSet.end()) {
                            if(newWord == endWord)
                                return ans + 1;
                            q.push(newWord);
                            wordSet.erase(newWord);
                        }
                    }
                }
            }
        }
        return 0;
    }
};