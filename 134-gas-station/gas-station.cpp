class Solution {
    // think of gas like earning and cost like spending
    // we can not traverse if our earning is less then our cost
    // but if it is more or equal then it is possible
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0;
        int totalCost = 0;

        for(int i = 0; i < n; i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalGas < totalCost) return -1;

        int station = 0;
        int current = 0;

        for(int i = 0; i < n; i++){
            // gas[i] - cost[i] + current is cost for moving forward
            // if that becomes negative then this cant be our station
            if(current + gas[i] - cost[i] < 0) {
                current = 0;
                station = i + 1; // check with this station
            } else {
                current += gas[i] - cost[i];
            }
        }

        return station;
    }
};