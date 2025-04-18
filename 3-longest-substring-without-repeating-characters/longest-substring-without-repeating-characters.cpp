class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        int left = 0;

        unordered_map<char, int> lastSeen; // stores last seen index for that character

        for(int right = 0; right < n; right++){
            char ch = s[right];

            // if we have alrady seen this character and this is our part of our current window then this substring has been broken since a repeat was found. start new from just after this index
            if(lastSeen.find(ch) != lastSeen.end() && lastSeen[ch] >= left){
                left = lastSeen[ch] + 1;
            }

            lastSeen[ch] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;


        // brute force approach can be to create all substrings and keep on calculating max length till no repeating is found
        // T.C => O(N ^ 2) and S.C => O(256) which is O(1) only
        /*int maxLen = 0;

        for(int i = 0; i < n; i++){
            unordered_set<char> seen;
            seen.insert(s[i]);
            int len = 1;
            for(int j = i + 1; j < n; j++){
                if(seen.find(s[j]) != seen.end()){
                    break;
                }
                len++;
                seen.insert(s[j]);
            }
            maxLen = max(maxLen, len);
        }

        return maxLen;
        */
    }
};