class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();

        if(k >= arr.size()) {
            int maxElement = INT_MIN;
            for(auto num: arr) maxElement = max(maxElement, num);
            return maxElement;
        }

        unordered_map<int, int> mp;

        int i = 1;

        while(i < n){
            if(arr[i] < arr[0]) {
                mp[arr[0]]++;
                i++;
            } else {
                swap(arr[0], arr[i]);
                mp[arr[0]]++;
                i++;
            }

            if(mp[arr[0]] >= k) return arr[0];
        }

        if(i == n) {
            int maxElement = INT_MIN;
            for(auto num: arr) maxElement = max(maxElement, num);
            return maxElement;
        }

        return -1;
    }
};