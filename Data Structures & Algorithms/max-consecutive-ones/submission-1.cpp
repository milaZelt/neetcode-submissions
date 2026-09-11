#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int bestStrike=0;
        int currentStrike=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                currentStrike++;
                if (currentStrike>bestStrike){
                    bestStrike=currentStrike;
                }
            }else{
                currentStrike=0;
            }
        }
        return bestStrike;
    }
};