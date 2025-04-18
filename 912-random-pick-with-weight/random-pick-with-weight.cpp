// think of each weight now as a range of numbers on a line
// ex. for 1, 3, 2 then [1, 3, 3, 3, 2, 2] is basically just a range only
// 1, 3, 2 => [1, 4, 6] 1, 4 represents all 3 before 1 is before 1 and 4, 6 represents 2

class Solution {
private:
    int totalSum = 0;
    vector<int> prefixSum;
public:
    Solution(vector<int>& w) {
        for(int weight: w){
            totalSum += weight;
            prefixSum.push_back(totalSum);
        }        
    }
    
    int pickIndex() {
        int randomNumber = rand() % totalSum + 1; // find a random number b/w [1, totalSum] wherever this random number lies return that index
        for(int i = 0; i < prefixSum.size(); i++){
            if(randomNumber <= prefixSum[i]) return i;
        }
        return -1;
    }
};

// brute force approach think of it like this
// if we have say 3 people 1st one has 2 tickets, 2nd one has 4 ticekts and 3rd one has 3 tickets and put it in a bowl and randomly pick them then 2nd person will have most probability of getting picked
// ex. in form of array [1, 1, 2, 2, 2, 2, 3, 3, 3] arr[i] represent is a ticket owned by arr[i] person
// class Solution {
// private:
//     vector<int> tickets;
// public:
//     Solution(vector<int>& w) {
//         for(int i = 0; i < w.size(); i++){
//             for(int j = 0; j < w[i]; j++){
//                 tickets.push_back(i); // insert this many tickets
//             }
//         }
//     }
    
//     int pickIndex() {
//         int randomIndex = rand() % tickets.size();
//         return tickets[randomIndex];
//     }
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */