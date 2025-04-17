class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // better approach
        int i = m - 1;
        int j = n - 1;

        int toInsertIdx = nums1.size() - 1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[toInsertIdx] = nums1[i];
                i--;
            } else{
                nums1[toInsertIdx] = nums2[j];
                j--;
            }
            toInsertIdx--;
        }

        while(j >= 0) {
            nums1[toInsertIdx] = nums2[j];
            j--;
            toInsertIdx--;
        }
        
        // brute force approach uses extra space
        // T.C => O(M + N) S.C => O(M + N)
        // vector<int> numsCopy;
        // int i = 0;
        // int j = 0;

        // while(i < m && j < n){
        //     if(nums1[i] > nums2[j]){
        //         numsCopy.push_back(nums2[j]);
        //         j++;
        //     } else {
        //         numsCopy.push_back(nums1[i]);
        //         i++;
        //     }
        // }

        // while(i < m){
        //     numsCopy.push_back(nums1[i]);
        //     i++;
        // }

        // while(j < n){
        //     numsCopy.push_back(nums2[j]);
        //     j++;
        // }

        // for(int i = 0; i < numsCopy.size(); i++){
        //     nums1[i] = numsCopy[i];
        // }
    }
};