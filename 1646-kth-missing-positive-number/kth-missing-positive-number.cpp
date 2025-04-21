class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        int n = arr.size();
        int num = 1;

        // num stores what the actual number at that position shoule have been
        while(i < n && k > 0){
            // if its same then not missing
            if(arr[i] == num) i++;
            else k--; // found missing number which should have been num

            num++;
        }

        while(k--){
            num++;
        }

        return num - 1;
    }
};