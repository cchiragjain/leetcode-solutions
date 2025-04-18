class Solution {
private:
    bool checkPalindrome(int i, int j, string s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int i = 0;
        int j = n - 1;

        while(i < j){
            // if we found a mis match then it could be the case we can either remove ith character and the new string from i + 1 -> j is a palindrome or we can remove the jth and new from i -> j - 1 is a palindrome
            if(s[i] != s[j]){
                return checkPalindrome(i + 1, j, s) || checkPalindrome(i, j - 1, s);
            }
            i++;
            j--;
        }

        return true;
    }
};