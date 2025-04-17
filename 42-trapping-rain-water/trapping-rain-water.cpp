class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int result = 0;

        // precompute left and right max for each index i
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = arr[0];
        rightMax[n - 1] = arr[n - 1];

        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i - 1], arr[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }

        for(int i = 0; i < n; i++){
            result += min(leftMax[i], rightMax[i]) - arr[i];
        }
        return result;

        // brute force approach T.C => O(N ^ 2)
        // if we are standing at any index then that index can at max hold the maximum height building from its left and right minimum. It is bound by that usse upar it will overflow
        // for each index calculate left and right max and then keep on addding it
        // for(int i = 0; i < n; i++){
        //     int leftMax = arr[i];
        //     for(int j = i - 1; j >= 0; j--){
        //         leftMax = max(arr[j], leftMax);
        //     }

        //     int rightMax = arr[i];
        //     for(int j = i + 1; j < n; j++){
        //         rightMax = max(arr[j], rightMax);
        //     }
        //     // use the 2nd example and check for 0 index it will make senese
        //     result += min(leftMax, rightMax) - arr[i];
        // }

        // return result;
    }
};