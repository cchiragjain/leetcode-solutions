class Solution {
private:
    int solve(int idx, int n, int difference, vector<int>& arr, vector<int>& memo){
        // if(idx >= n) return 0;

        if(memo[idx] != -1) return memo[idx];

        int result = 0;
        for(int j = idx + 1; j < n; j++){
            int prevVal = arr[idx];
            int currVal = arr[j];
            if(currVal - prevVal == difference){
                // include this in our result
                // there is no concept of not take here, no need for this since we need to find the longest only
                result = max(result, 1 + solve(j, n, difference, arr, memo));
            }
        }

        return memo[idx] = result;
    }

public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        int result = 0;
        // recursion + memoisation giving tle O(N ^ 2 approach)
        // vector<int> memo(n, -1);

        // for(int i = 0; i < n; i++){
        //     // start from this ith index and check for whether we can create subseqeuenc or not
        //     result = max(result, 1 + solve(i, n, difference, arr, memo));
        // }

        // return result;

        unordered_map<int, int> mp; // this stores for each element how longer subsequence it can form for the given condition
        // say difference was 2 and 3 => 2 then if we are at 5 while traversing then we can just check if 5 - 2 = 3 exists in our map and take length of subsequence from that and keep on iterating
        int maxVal = 1;
        for(int i = 0; i < n; i++){
            if(mp.find(arr[i] - difference) != mp.end()){
                // some adjacent element exists from before
                mp[arr[i]] = mp[arr[i] - difference] + 1; // take length of previos subsequence and add current elemetn to it
                maxVal = max(maxVal, mp[arr[i]]);
            } else {
                mp[arr[i]] = 1; // first occurence
            }
        }

        return maxVal;
    }
};