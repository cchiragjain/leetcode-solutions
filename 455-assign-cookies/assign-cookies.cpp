class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort both greed and size so that children with the least greed have the small size cookies
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int i = 0;
        int j = 0;

        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                count++;
                i++;
                j++;
            } else{
                j++; // this cookie size can not be assigned since more i will be larger values of greed
            }
        }

        return count;
    }
};