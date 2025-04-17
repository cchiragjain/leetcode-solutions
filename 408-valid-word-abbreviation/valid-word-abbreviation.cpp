class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m = word.length();
        int n = abbr.length();

        int i = 0;
        int j = 0;

        while(i < m && j < n){
            if(isdigit(abbr[j])){
                if(abbr[j] == '0') return false; // cant have leading zeros in a new number also others will be covered by jump

                // if its a digit we need to make this many jumps in our word string
                // no leading zeros are allowed as well

                // but can be case two numbers are together
                // ex. jump can be of 10 steps
                int num = 0;
                while(j < n && isdigit(abbr[j])){
                    // convert to number
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }

                i+= num; // make this many jumps in our word string now
            } else {
                if(word[i] != abbr[j]) return false;
                i++; j++;
            }
        }

        return i == m && j == n; // both strings got exhausted
    }
};