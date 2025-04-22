class Solution {
private:
    int canPlaceMBallsUsingThisForce(vector<int>& position, int force, int m){
        int count = 1;
        int lastPlacedPosition = position[0];

        for(int i = 1; i < position.size(); i++){
            if(abs(position[i] - lastPlacedPosition) >= force){
                count++;
                lastPlacedPosition = position[i];
            }
        }

        if(count >= m) return true;
        return false;
    }

public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int minF = 1;
        int maxF = position.back() - position[0];

        int start = minF;
        int end = maxF;

        while(start <= end){
            int mid = start + (end - start) / 2;

            if(canPlaceMBallsUsingThisForce(position, mid, m)){
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return end;

        // for(int i = minF; i <= maxF; i++){
        //     if(!canPlaceMBallsUsingThisForce(position, i, m)){
        //         return i - 1;
        //     }
        // }

        // return maxF;
    }
};