#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        for(int i=0;i<nums.size(); i++){
            int sum=target-nums[i]; 
            auto it=find(nums.begin()+i+1,nums.end(), sum);
            if (it!=nums.end()){
                    int index=distance(nums.begin(), it);
                    return {i, index};      
            }
        }
        return {};
    }
};
