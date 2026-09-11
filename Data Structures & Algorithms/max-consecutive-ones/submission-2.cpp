#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int bestStrike=0;
        int currentStrike=0;

        for(int num: nums){
            if(num==1){
                currentStrike++;
                bestStrike=max (currentStrike,bestStrike);
            }else{
                currentStrike = 0;
            }
        }
        return bestStrike;
    }
};