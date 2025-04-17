class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        string res = "";
        bool word1Chance = true;

        while(i < word1.length() && j < word2.length()){
            if(word1Chance){
                res.push_back(word1[i]);
                i++;
            } else{
                res.push_back(word2[j]);
                j++;
            }

            word1Chance = !word1Chance;
        }

        while(i < word1.length()){
            res.push_back(word1[i]);
            i++;
        }

        while(j < word2.length()){
            res.push_back(word2[j]);
            j++;
        }

        return res;
    }
};