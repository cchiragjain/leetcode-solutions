class Solution {
private:
    // this returns the maxPoints required if we consider just num
    // we can take num and then not be able to take num - 1 or not take it and take all points accumulated till num - 1
    int maxPoints(int num, unordered_map<int,int>& points, unordered_map<int,int>& memo){
        if(num == 0) return 0;
        if(num == 1) return points[1];

        if(memo.find(num) != memo.end()) return memo[num];

        int notTake = 0 + maxPoints(num - 1, points, memo);
        int take = points[num] + maxPoints(num - 2, points, memo);
        
        memo[num] = max(take, notTake);

        return memo[num];
    }

    int maxPointsTabulation(vector<int>& nums){
        // find max number
        // then from 2 to max number create dp array using recurrence realtion new dp[max number + 1]
        // return dp[max number]
        // can be further optimisd to 2 variables like in fibonacci/ house robber
        return 0;
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> memo;
        unordered_map<int, int> points;
        int maxNumber = INT_MIN;

        // if we say take 3 then we can take all 3 since taking 3 will delete all 2's and 4's
        // so rather than count we are keeping count * element
        for(int num: nums){
            points[num] += num;
            // we dont want to sort the array increases complexity so our function will basically return maxPoints(4) which will consider whether to take 4 or not which will go to 3 and 2
            maxNumber = max(maxNumber, num); 
        }

        return maxPoints(maxNumber, points, memo);
    }
};