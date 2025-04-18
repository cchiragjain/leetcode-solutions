class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;

        for(int i = 0; i < n; i++){
            // if opening bracket push to stack
            // if closing bracket check if last pushed opening matches or not and also only check if non empty
            char bracket = s[i];
            if(bracket == '(' || bracket == '{' || bracket == '['){
                st.push(bracket);
            } else if(!st.empty()){
                char lastFoundBracket = st.top();
                st.pop();
                if(
                    !((lastFoundBracket == '(' && bracket == ')') ||
                    (lastFoundBracket == '[' && bracket == ']') ||
                    (lastFoundBracket == '{' && bracket == '}'))
                ) {
                    return false;
                }
            } else {
                return false; // st emtpy and found a closing bracket first
            }
        }

        if(st.empty()) return true;
        return false;
    }
};