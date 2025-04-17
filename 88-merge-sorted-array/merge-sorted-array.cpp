class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> numsCopy;
        int i = 0;
        int j = 0;

        while(i < m && j < n){
            if(nums1[i] > nums2[j]){
                numsCopy.push_back(nums2[j]);
                j++;
            } else {
                numsCopy.push_back(nums1[i]);
                i++;
            }
        }

        while(i < m){
            numsCopy.push_back(nums1[i]);
            i++;
        }

        while(j < n){
            numsCopy.push_back(nums2[j]);
            j++;
        }

        for(int i = 0; i < numsCopy.size(); i++){
            nums1[i] = numsCopy[i];
        }
    }
};