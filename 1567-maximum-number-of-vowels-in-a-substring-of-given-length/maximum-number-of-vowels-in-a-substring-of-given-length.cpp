class Solution {
private:
    bool isVowel(char ch){
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    
    }
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int maxCount;
        int vowelCount = 0;

        for(int i = 0; i < k; i++){
            if(isVowel(s[i])) vowelCount++;
        }

        maxCount = vowelCount;
        for(int i = k; i < n; i++){
            if(isVowel(s[i])) vowelCount++;
            if(isVowel(s[i - k])) vowelCount--;

            maxCount = max(maxCount, vowelCount);
        }

        return maxCount;

        // O(N * K) approach gives tle
        // for each substring of size k count vowels
        // int maxCount = 0;
        // for(int i = 0; i <= n - k; i++){
        //     int count = 0;
        //     for(int j = i; j < i + k; j++){
        //         if(isVowel(s[j])){
        //             count++;
        //         }
        //     }
            
        //     maxCount = max(maxCount, count);
        // }

        // return maxCount;
    }
};