class Solution {
private:
    void cleanSpaces(string& s){
        int i = 0;
        int j = 0;
        int n = s.length();

        while(j < n){
            while(j < n && s[j] == ' '){
                j++; // skip all leading spaces
                // i will keep track of where to replace character to
            }

            // copy characters to new places
            while(j < n && s[j] != ' '){
                s[i] = s[j];
                i++;
                j++;
            }

            while(j < n && s[j] == ' '){
                j++; // again clean all spaces
            }

            // if after all that j is remaining means j is at a new word there should be a space in original string
            if(j < n) {
                s[i] = ' ';
                i++;
            }
        }

        s.resize(i);
    }

    void reverse(int i, int j, string& s){
        while(i < j){
            swap(s[i], s[j]);
            i++; j--;
        }
    }
public:
    string reverseWords(string s) {
        // T.C => O(N) and S.C => O(N)
        // brute force will be to just whenever found space add previous word formed till now it to new vector 
        // then reverse the vector
        // and then join in a string values of this vector

        // but can also do in place using pointers
        // first step is to remove extra spaces from string
        int start = 0;
        cleanSpaces(s);
                int n = s.length();
        reverse(0, n - 1, s);

        // now string is clean and is reversed entirely
        // find a word and now reverse it separately

        for(int i = 0; i <= n; i++){
            // a new word can only be formed at a space or if the string has been covered
            if(i == n || s[i] == ' '){
                reverse(start, i - 1, s);
                start = i + 1;
            }
        }

        return s;
    }
};