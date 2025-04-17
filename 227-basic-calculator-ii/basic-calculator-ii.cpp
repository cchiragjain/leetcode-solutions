class Solution {
public:
    int calculate(string s) {
        int n = s.length();

        stack<int> st; // will solve all resolved which we can just add

        int num = 0; // there can be multi digit input as well
        int result = 0; // final result
        char lastOperation = '+';

        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                num = num * 10 + (s[i] - '0');
            }

            if((!isdigit(s[i]) && s[i] != ' ') || i == n - 1){
                // check what was the last operation we needed to do with this number when it started creating
                // if addition and subtraction they will have lower precedence
                // mulitplication and division will be done here for further use
                if(lastOperation == '+'){
                    st.push(num);
                } else if(lastOperation == '-'){
                    st.push(-num); // this number should be subtracted from the total
                } else if(lastOperation == '/'){
                    int temp = st.top();
                    st.pop();
                    st.push(temp/num); // for 5 / 2 5 was in the stack / was last operation and 2 is new num
                } else if(lastOperation == '*'){
                    int temp = st.top();
                    st.pop();
                    st.push(temp * num);
                }

                num = 0;
                lastOperation = s[i];
            }
        }

        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        return result;
    }
};