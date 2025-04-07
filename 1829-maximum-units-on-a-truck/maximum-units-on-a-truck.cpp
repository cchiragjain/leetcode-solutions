class Solution {
private:
    // sorts in descending order on the basis of second element
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // sort box types on the basis of units so that the first boxes we put on the truck have the maximum units in order to maximise units
        sort(boxTypes.begin(), boxTypes.end(), cmp);

        int maxUnits = 0;

        for(int i = 0; i < boxTypes.size(); i++){
            int boxes = boxTypes[i][0];
            int unitsInABox = boxTypes[i][1];

            // will auto stop if at any time truckSize becomes negative since boxes count is >= 1
            if(boxes <= truckSize){
                truckSize -= boxes;
                maxUnits += (boxes * unitsInABox);
            } else if(truckSize > 0){
                // ex. if size remaining was 2 and we had 4 boxes
                // then can still use 2 boxes to fill up the truck
                int boxesUsed = truckSize;
                truckSize -= boxesUsed;
                maxUnits += (boxesUsed * unitsInABox);
            }
        }

        return maxUnits;
    }
};