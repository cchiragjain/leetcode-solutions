#define ll long long
class Solution {
private:
    ll calculateSum(int x, int length){
        if(x > length) {
            // check below for calculation
            return (ll)length * x - (ll)length * (length + 1) / 2;
        } else {
            // sum of first x elements + calculate remaining 1's
            return (ll)x * (x - 1) / 2 + (ll)(length - (x - 1)); 
        }
    }

public:
    int maxValue(int n, int index, int maxSum) {
        int start = 1;
        int end = maxSum;
        int result = 1;

        while(start <= end){
            int mid = start + (end - start) / 2;

            ll total = mid;

            total += calculateSum(mid, index);
            total += calculateSum(mid, n - index - 1);

            if(total <= maxSum){
                result = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return result;
        // brute force
        // T.C => O(maxSum * n ( for creating left and right max Sum))
        // start from max sum try to place it at index
        // and go to left keep on placing maxSum-- elements cant be 0
        // go to right and keep on placing 
        // if i + leftSum + rightSum <= maxSum then return i since it can be placed at index

        /*
            we can improve calculating sum from left and right from O(N) to O(1)

            say if we are at x and there are 4 elements behind x
            then left sum is
            (x - 4) + (x - 3) + (x - 2) + (x - 1)
            = 4 * x - ( 1 + 2 + 3 + 4 )
            = leftElementCount * x - (sum of leftElementCount numbers)

            similarly for right Sum        

            but can be case that x < length required so we will need to use 1
        */

        // for(int i = maxSum; i >= 1; i--){
        //     ll total = i;

        //     total += calculateSum(i, index) + calculateSum(i, n - index - 1);

        //     if(total <= maxSum) return i;

            // int leftVal = i - 1; // can also place i but need to minimise so that dont exceed maxsum
            // for(int j = index - 1; j >= 0; j--){
            //     total += leftVal > 1 ? (ll)leftVal : 1;
            //     leftVal--;
            // }

            // int rightVal = i - 1;
            // for(int j = index + 1; j < n; j++){
            //     total += rightVal > 1 ? (ll)rightVal : 1;
            //     rightVal--;
            // }

            // if(total <= maxSum){
            //     return i;
            // }
        // }

        // return -1;    
    }
};