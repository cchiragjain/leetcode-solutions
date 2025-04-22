class Solution {
private:
    int countLessEqual(vector<vector<int>>& matrix, int mid){
        int count = 0;

        int row = 0;
        int col = matrix.size() - 1;

        while(row < matrix.size() && col >= 0){
            if(matrix[row][col] <= mid){
                count += col + 1;
                row++;
            } else {
                col--;
            }
        }

        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // t.c => O(N ^ 2) s.c => O(k)
        // brute will be to put into a max heap and if at any time size > k then pop
        // return top element

        // we can do is from min matrix and max in matrix find that number which will have exactly <= k elements smaller than it
        int n = matrix.size();
        int start = matrix[0][0];
        int end = matrix[n - 1][n - 1];

        while(start <= end){
            int mid = start + (end - start) / 2;

            // count how many elements are less than or equal to this mid element
            if(countLessEqual(matrix, mid) >= k) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};