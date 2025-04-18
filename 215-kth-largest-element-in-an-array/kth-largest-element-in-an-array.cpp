class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // we ccan also create a min heap of size k and keep on inserting elements in it
        // if size > k then pop the top element this will ensure size k only and will at end store k largest element in it
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        // at any time pq will have the top k element seen till ith index
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }

        return pq.top();
        // very brute force approach will be to sort in descending order and return k - 1 the element
        // this will have time complexity of O(N log N)
        // sort(nums.begin(), nums.end(), greater<int>());
        // return nums[k - 1];
    }
};