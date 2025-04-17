class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st;

        int result = 0; // this will store the final result
        int number = 0; // this will have the current number we are working on can also have multidigits
        int sign = 1; // this will store the sign 1 means positive and - 1 means negative. Whenever we will be adding and subtracting will be doing using this

        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                // start adding to our number
                // since valid string only cant start with other
                number = number * 10 + (s[i] - '0');
            } else if(s[i] == '+'){
                // a number has been formed this should be added to our result
                // after this plus a new number will get formed only
                result += number * sign; // if last sign was negative then this newly created number will be subtracted
                number = 0;
                sign = 1;
            } else if(s[i] == '-'){
                // a number has been formed this should be added to our result
                // after this plus a new number will get formed only
                result += number * sign; // if last sign was negative then this newly created number will be subtracted
                number = 0;
                sign = -1;
            } else if(s[i] == '('){
                // think of this like a subproblem now
                // store the current result and sign in a stack and start solving this new problem
                st.push(result);
                st.push(sign);
                number = 0;
                result = 0;
                sign = 1;
            } else if(s[i] == ')'){
                // number and result will have whatever was solved in the bracket
                result += number * sign;
                number = 0;
                int stack_sign = st.top(); st.pop();
                int stack_result = st.top(); st.pop();

                result *= stack_sign; // whatever was last sign this would
                // ex. we could be haveing something - ( some )
                result += stack_result;
            }
        }

        result += number * sign; // there may be cases where we end up missing the last character
        return result;
    }
};