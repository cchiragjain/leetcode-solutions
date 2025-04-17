class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();

        string res = "";
        stack<int> st; // will store indexes of any open bracket found
        unordered_set<int> tracker;

        for(int i = 0; i < n; i++){
            if(s[i] == '(') st.push(i);
            else if(!st.empty() && s[i] == ')'){
                st.pop();
            } else if(st.empty() && s[i] == ')'){
                // stack is used for matching and unmatching
                // no insert in stack there 
                tracker.insert(i);
            }
        }

        while(!st.empty()){
            tracker.insert(st.top());
            st.pop();
        }

        for(int i = 0; i < n; i++){
            // if not able to find this index in our set then that means inserting only these will make our string valid
            if(tracker.find(i) == tracker.end()){
                res.push_back(s[i]);
            }
        }

        return res;
    }
};