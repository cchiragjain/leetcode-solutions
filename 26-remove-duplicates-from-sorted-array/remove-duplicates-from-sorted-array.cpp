class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();

        while(j < n){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
                j++;
            } else {
                j++;
            }
        }

        return i + 1;
    }
};