class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        
        int l = 0, r = n-1;
        
        while(l <= r) {
            int mid = l + (r-l)/2;
            // if standing at 4 then there should actually been 3 there if no missing then 4 - 3 = 1 is how many missing elements till there

            if(arr[mid] - (mid+1) < k) { //A[mid]-(mid+1)   --> This gives umber of missing number before m'th index
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        
        return l + k;
        /*
        brute O(N)
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
        */
    }
};