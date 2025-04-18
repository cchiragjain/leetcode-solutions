class Solution {
private:
    int partition(int left, int right, vector<int>& nums){
        int i = left + 1;
        int j = right;
        int pivot = nums[left];

        while(i <= j){
            if(nums[i] < pivot && nums[j] > pivot) {
                swap(nums[i], nums[j]);
                i++; j--; // i and j are now at correct position
            }

            if(nums[i] >= pivot) {
                i++;
            }

            if(nums[j] <= pivot){
                j--;
            }
        }

        swap(nums[left], nums[j]);
        return j;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
            can be solved using quick select algorithm as well
        */
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int pivotIdx = 0;

        while(true){
            // partition array such that for this left and right and given pivot idx the array becomes such that all to the left of pivot idx are greater than that element and all to the left are smaller 

            pivotIdx = partition(left, right, nums);
            if(pivotIdx == k - 1) break;

            else if(pivotIdx > k - 1){
                // we found pivot idx on the right side ex. found 4th largest wehen wantted to find 2nd largets
                right = pivotIdx - 1;
            } else if(pivotIdx < k - 1) {
                left = pivotIdx + 1;
            }
        }

        return nums[k - 1];
        /*
        Using min heap O(N log K) but k can be N as well in worst case
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
        */

        /* Brute
        // very brute force approach will be to sort in descending order and return k - 1 the element
        // this will have time complexity of O(N log N)
            sort(nums.begin(), nums.end(), greater<int>());
            return nums[k - 1];
        */
    }
};