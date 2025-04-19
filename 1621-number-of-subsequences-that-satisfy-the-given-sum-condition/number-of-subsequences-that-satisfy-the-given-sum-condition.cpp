class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        // brute force will be to generate all subsequences which will be 2^n and then for all check min and max
        // will be n * 2 ^ n

        // if we see from a sub we only need its min and max values. so a sub like 3, 5, 6 is same as 5, 3, 6
        // basically can consider them as subsets
        // and sort the array

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int result = 0;
        int l = 0;
        int r = n - 1;
        int mod = 1e9 + 7;

        vector<int> power(n, 1);

        for(int i = 1; i < n; i++){
            power[i] = (power[i - 1] * 2) % mod;
        }

        while(l <= r){
            if(nums[l] + nums[r] <= target){
                // if the array is sorted and using l and r sub we are within target then any sub using l and r - 1 ... etc will also be in target

                // ex. 3, 5, 6, 7 l = 0 and r = 2 then using 3 create all subs of 5 and 6 which is 2 ^ 2
                // 3
                // 3, 5
                // 3, 6
                // 3, 5, 6

                // this line will be outside int range
                // result += pow(2, r - l);

                result = ((result % mod) + power[r - l]) % mod;
                l++; // taken this element create for others
            } else {
                r--; // to big r will not be able to take this any how
            }
        }
        
        return result;
    }
};