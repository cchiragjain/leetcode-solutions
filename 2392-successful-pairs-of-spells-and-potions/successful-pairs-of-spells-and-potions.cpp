class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // brute is to for every spell go through each portion and check how many spell[i] * potion[j] >= sucess
        // and result[i]++

        // result order is dependent on spells i 

        sort(potions.begin(), potions.end());
        vector<int> result;

        // if we need to find spell * potion >= sucess
        // potion >= success / spell 
        // so for each spell basically find lower bound in potion

        for(int spell: spells){
            long long minPotion = ceil((double)success / (double)spell);

            auto it = lower_bound(potions.begin(), potions.end(), minPotion);

            if(it != potions.end()){
                result.push_back(
                    potions.size() - (it - potions.begin())
                );
            } else {
                result.push_back(0);
            }
        }

        return result;
    }
};