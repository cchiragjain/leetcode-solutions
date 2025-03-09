class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int result = 0;

        queue<pair<string, int>> q; // stores word vs the level this word was formed on
        // ex. beginWord is at level 1 -> then after a single transformation it is at level 2
        unordered_set<string> wordMap;

        q.push({beginWord, 1});
        // create a map of all available words for O(1) access later
        for(string word: wordList){
            wordMap.insert(word);
        }

        while(!q.empty()){
            string currentWord = q.front().first;
            int level = q.front().second;

            q.pop();

            // if at any moment we reach the end word then return the level
            if(currentWord == endWord){
                return level;
            }

            // now for each charcter in this word we are doing a change and testing if it
            // exists in our allowed words or not
            // if it exists then again for that word check for all characters
            // also remove this word from set since can land again at this word through other transformations.
            for(int i = 0; i < currentWord.size(); i++){
                string testWord = currentWord;
                for(char c = 'a'; c <= 'z'; c++){
                    testWord[i] = c;
                    if(wordMap.find(testWord) != wordMap.end()){
                        q.push({testWord, level + 1});
                        wordMap.erase(testWord);
                    }
                }
            }
        }

        return result;
    }
};