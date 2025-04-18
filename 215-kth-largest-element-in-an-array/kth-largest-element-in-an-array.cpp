class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // very brute force approach will be to sort in descending order and return k - 1 the element
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};