#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP=0;
        int left=0;

        for(int right=0; right<prices.size(); right++){
            if(prices[left]>prices[right]){
                left=right;
            }
            int profit=prices[right]-prices[left];
            maxP=max(profit, maxP);
        }
        return maxP;
    }
};
