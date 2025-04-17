class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxProfit = 0;
        int minPrice = INT_MAX;

        for(int i = 0; i < n;i++){
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            } // else if using this price as our selling price if we are able to update our profit then use this price
            else if(prices[i] - minPrice > maxProfit){
                maxProfit = prices[i] - minPrice;
            }
        }

        return maxProfit;
        // maintain minPrice seen till now and maxProfit acheived using that price
        // if new minPrice is found then update it for future

        // brute force approach T.C => O(N^2)
        // for(int i = 0; i < n; i++){
        //     int buyPrice = prices[i];
        //     for(int j = i + 1; j < n; j++){
        //         int sellPrice = prices[j];
        //         maxProfit = max(maxProfit, sellPrice - buyPrice);
        //     }
        // }

        // return maxProfit;
    }
};