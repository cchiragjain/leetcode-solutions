class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) { 
        // can remove the need for separate space all together in case of two pointer approahc by simulating k 
        int i = 0;
        int j = 0;
        int k = 0;

        int m = nums1.size();
        int n = nums2.size();

        int idx1 = (m + n) / 2;
        int idx2 = (m + n) / 2 - 1;
        int element1 = -1;
        int element2 = -1;

        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                if(k == idx1) {
                    element1 = nums1[i];
                } else if(k == idx2){
                    element2 = nums1[i];
                }
                i++;
            } else {
                if(k == idx1) {
                    element1 = nums2[j];
                } else if(k == idx2){
                    element2 = nums2[j];
                }
                j++;
            }
            k++;
        }

        while(i < m){
            if(k == idx1) {
                    element1 = nums1[i];
                } else if(k == idx2){
                    element2 = nums1[i];
                }
                i++;
                k++;
        }
        while(j < n){
            if(k == idx1) {
                    element1 = nums2[j];
                } else if(k == idx2){
                    element2 = nums2[j];
                }
                j++;
                k++;
        }

        if((m + n)% 2 == 1) return element1 / 1.0;

        return (element1 + element2) / 2.0;
        // better approach will be to use 2 pointers i and j and in new vector only add smaller elememnt and keep on iterating
        // T.C => O(M + N) S.C => O(M + N)

        // brute force approach will be to just create a new vector of m + n fill it with values from nums1 and nums2 and then sort this.
        // then return median based on m + n size
        // T.C => O(M + N ( log M + N ))
    }
};