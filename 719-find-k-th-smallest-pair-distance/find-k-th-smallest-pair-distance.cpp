class Solution {
private:
    int countPairs(vector<int>& nums, int maxDist) {
        int count = 0, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > maxDist) {
                left++;
            }
            count += right - left;
        }
        return count;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // very brute will be to generate all i, j pairs and for that calculate distance and store in vector
        // now sort ascending and return k - 1 element
        // t.c => O(n ^ 2 ) + O(n2 log n2) => O(n ^ 2 log n)
        // s.c => O(n ^ 2)

        // rather than sorting we can push to max heap and maintain size of heap no more than k. then at top will be kth smallest 
        // t.c O(n ^ 2 log K)
        // s.c O(n^2)

        sort(nums.begin(), nums.end());
        int low = 0, high = nums[nums.size() - 1] - nums[0];

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = countPairs(nums, mid);

            if (count < k) low = mid + 1;
            else high = mid - 1;
        }

        return low;
    }
};