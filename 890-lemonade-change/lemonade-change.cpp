class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount = 0;
        int tenCount = 0;

        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5) {
                // no change is needed to be given back
                // just incrememnt
                fiveCount++;
            } else if(bills[i] == 10){
                // can only be possible if we have atleast one five dollar bill
                if(fiveCount > 0){
                    fiveCount--;
                    tenCount++;
                } else {
                    return false;
                }
            } else {
                // if bill is 20 then there are 2 cases
                // either 10 + 5 or 5 + 5 + 5 needs to be returned
                // but we need max 5 so best to first check 10 dollar bills
                if(tenCount > 0 && fiveCount > 0){
                    tenCount--;
                    fiveCount--;
                } else if(fiveCount >= 3){
                    fiveCount -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};