#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minlen=INT_MAX; //answer
        int left=0;
        int sum=0;

        for(int right=0; right<nums.size(); right++){
            sum+=nums[right];

            while (sum>=target){
                minlen = min(minlen, right - left + 1);
                
                //sum is big enought can remove one number
                sum-=nums[left];
                left++;
            }
        }
        if (minlen==INT_MAX){
            return 0;
        }else {
            return minlen; 
        }
    }
};