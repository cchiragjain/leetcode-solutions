class Solution {
private:
    bool canMakePPairs(vector<int>& nums, int difference, int pairCount){
        // int left = 0;
        int count = 0;
        int i = 1;
        
        while(i < nums.size()){
            if(nums[i] - nums[i - 1] <= difference){
                count++;
                i += 2; // skip the next one to keep pairs disjoint
            } else {
                i++; // try next pair
            }
        }

        // for(int right = 0; right < nums.size(); right++){
        //     while(abs(nums[right] - nums[left]) > difference) left++;

        //     count += right - left;
        // }


        if(count >= pairCount) return true;
        return false;
    }

public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int start = 0; // min possible differencce
        int end = nums.back() - nums[0]; // max difference possible

        while(start <= end){
            int mid = start + (end - start) / 2;

            // check if using this difference can make p pairs
            if(canMakePPairs(nums, mid, p)){
                // result = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};